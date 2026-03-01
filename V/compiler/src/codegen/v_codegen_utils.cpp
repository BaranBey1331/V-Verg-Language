#include "v_codegen_utils.hpp"

namespace VCodeGenUtils {

    std::string getCoreHeaders() {
        std::string headers = "#include <string>\n#include <memory>\n#include \"v_runtime.hpp\"\n";
        headers += "#include \"v_memory.hpp\"\n\n"; 

        // === VDISCORD VE YENİ ÖZELLİKLERİN C++ KÖPRÜLERİ ===
        headers += "extern \"C\" {\n";
        headers += "    void vdiscord_setup(const char* token, int zero_cache, int intents);\n";
        headers += "    void vdiscord_login();\n";
        headers += "    void vdiscord_send_message(const char* channel_id, const char* content);\n";
        
        // Yeniler: Embed ve Renkli Mesajlar (Derleyici artik onlari taniyacak!)
        headers += "    void vdiscord_create_embed(const char* title, const char* description, int color);\n";
        headers += "    void vdiscord_add_embed_field(const char* name, const char* value, int inline_field);\n";
        headers += "    void vdiscord_send_embed(const char* channel_id);\n";
        headers += "    void vdiscord_send_colored(const char* channel_id, const char* text, const char* color);\n";
        headers += "}\n\n";
        
        return headers;
    }

    std::string getStartupCode() {
        return "    // V-Engine Ultra-Fast Arena Init\n    v_core::EngineArena.reset();\n\n";
    }

    bool checkBranchlessEligibility(IfNode* iNode, std::string& out_target_var) {
        if (iNode->if_body.size() == 1 && !iNode->else_body.empty() && iNode->else_body.size() == 1) {
            if (iNode->if_body[0]->nodeType() == "Assignment" && iNode->else_body[0]->nodeType() == "Assignment") {
                auto if_assign = static_cast<AssignmentNode*>(iNode->if_body[0]);
                auto else_assign = static_cast<AssignmentNode*>(iNode->else_body[0]);
                if (if_assign->var_name == else_assign->var_name) {
                    out_target_var = if_assign->var_name;
                    return true;
                }
            }
        }
        return false;
    }

    std::string buildCompilerCommand(const std::string& cpp_file, const std::string& bin_file) {
        std::string cmd = "clang++ -O3 -march=native -fno-strict-aliasing -fno-exceptions -fno-rtti -std=c++17 -Iinclude ";
        cmd += cpp_file + " stdlib/*.cpp src/core/*.cpp src/codegen/v_codegen_utils.cpp -L. -lvdiscord -Wl,-rpath,. -o " + bin_file;
        return cmd;
    }
}
