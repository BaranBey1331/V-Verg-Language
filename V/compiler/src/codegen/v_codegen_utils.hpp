#pragma once
#include <string>

// DIKKAT: Kendi AST/Dugum dosyanin adi her neyse (ast.hpp, nodes.hpp vb.) onu buraya dogru yazmalisin.
// Eger src klasorundeyse "../ast.hpp" olur.
#include "ast.hpp" 

namespace VCodeGenUtils {
    std::string getCoreHeaders();
    std::string getStartupCode();
    bool checkBranchlessEligibility(IfNode* iNode, std::string& out_target_var);
    std::string buildCompilerCommand(const std::string& cpp_filename, const std::string& bin_filename);
}
