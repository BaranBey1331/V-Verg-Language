#include "codegen.hpp"
#include "ast.hpp"
#include "v_codegen_utils.hpp" // YAN DOSYAMIZI DAHIL ETTIK!
#include <fstream>
#include <iostream>
#include <cstdlib>

CodeGenerator::CodeGenerator() : indent_level(0) {
    // 1. Yaverimizden (Utils) ust basliklari aliyoruz
    cpp_code = VCodeGenUtils::getCoreHeaders();

    cpp_code += "int main(int argc, char* argv[]) {\n";
    indent_level++;
    
    // 2. Yaverimizden baslangic optimizasyonlarini (Arena Reset) aliyoruz
    cpp_code += VCodeGenUtils::getStartupCode();
}

void CodeGenerator::write(const std::string& text) { 
    cpp_code += text; 
}

void CodeGenerator::writeLine(const std::string& text) {
    for(int i = 0; i < indent_level; i++) cpp_code += "    ";
    cpp_code += text + "\n";
}

void CodeGenerator::visit(ASTNode* node) {
    if (!node) return;
    std::string type = node->nodeType();

    if (type == "Number") {
        write(static_cast<NumberNode*>(node)->value);
    } 
    else if (type == "String") {
        write("\"" + static_cast<StringNode*>(node)->value + "\"");
    } 
    else if (type == "Identifier") {
        write(static_cast<IdentifierNode*>(node)->name);
    } 
    else if (type == "BinaryOp") {
        auto b = static_cast<BinaryOpNode*>(node);
        write("(");
        visit(b->left);
        write(" " + b->op + " ");
        visit(b->right);
        write(")");
    } 
    else if (type == "VarDecl") {
        auto v = static_cast<VarDeclNode*>(node);
        for(int i=0; i<indent_level; i++) write("    ");
        write("auto " + v->var_name + " = "); 
        visit(v->value);
        write(";\n");
    } 
    else if (type == "Assignment") {
        auto a = static_cast<AssignmentNode*>(node);
        for(int i=0; i<indent_level; i++) write("    ");
        write(a->var_name + " = ");
        visit(a->value);
        write(";\n");
    } 
    else if (type == "MethodCall") {
        auto m = static_cast<MethodCallNode*>(node);
        for(int i=0; i<indent_level; i++) write("    ");
        
        if (m->object_name == "std") write("v_std::" + m->method_name + "(");
        else if (m->object_name == "djs") write("vdiscord_" + m->method_name + "(");
        else write(m->object_name + "." + m->method_name + "(");
        
        for (size_t i = 0; i < m->arguments.size(); ++i) {
            visit(m->arguments[i]);
            if (i < m->arguments.size() - 1) write(", ");
        }
        write(");\n");
    } 
    else if (type == "While") {
        auto w = static_cast<WhileNode*>(node);
        for(int i=0; i<indent_level; i++) write("    ");
        write("while (");
        visit(w->condition);
        write(") {\n");
        indent_level++;
        for (auto* stmt : w->body) visit(stmt);
        indent_level--;
        writeLine("}");
    } 
    else if (type == "If") {
        auto i = static_cast<IfNode*>(node);
        std::string target_var;
        
        // 3. Yaverimize (Utils) soruyoruz: "Bu IF blogunu Dalsiz (Branchless) yapabilir miyiz?"
        if (VCodeGenUtils::checkBranchlessEligibility(i, target_var)) {
            auto if_assign = static_cast<AssignmentNode*>(i->if_body[0]);
            auto else_assign = static_cast<AssignmentNode*>(i->else_body[0]);
            
            for(int j=0; j<indent_level; j++) write("    ");
            write(target_var + " = (");
            visit(i->condition);
            write(") ? (");
            visit(if_assign->value);
            write(") : (");
            visit(else_assign->value);
            write(");\n");
        } 
        else {
            for(int j=0; j<indent_level; j++) write("    ");
            write("if (");
            visit(i->condition);
            write(") {\n");
            indent_level++;
            for (auto* stmt : i->if_body) visit(stmt);
            indent_level--;
            writeLine("}");
            if (!i->else_body.empty()) {
                writeLine("else {");
                indent_level++;
                for (auto* stmt : i->else_body) visit(stmt);
                indent_level--;
                writeLine("}");
            }
        }
    }
}

void CodeGenerator::generateCPP(const std::vector<ASTNode*>& ast, const std::string& out_filename) {
    for (auto* node : ast) visit(node);
    indent_level--;
    writeLine("    return 0;\n}");

    std::ofstream out_file(out_filename);
    out_file << cpp_code;
    out_file.close();
}

void CodeGenerator::compileToBinary(const std::string& cpp_filename, const std::string& bin_filename) {
    std::cout << "\033[1;33m[COMPILER]\033[0m V-Engine: Derleme Asamasi Basladi...\n";
    
    // 4. Yaverimizden (Utils) asiri optimize edilmis donanim derleme komutunu aliyoruz
    std::string cmd = VCodeGenUtils::buildCompilerCommand(cpp_filename, bin_filename);
    
    int result = std::system(cmd.c_str());
    if (result == 0) {
        std::cout << "\033[1;32m[BASARILI]\033[0m " << bin_filename << " basariyla uretildi!\n";
    } else {
        std::cout << "\033[1;31m[HATA]\033[0m C++ Linker veya Derleme Hatasi.\n";
    }
}
