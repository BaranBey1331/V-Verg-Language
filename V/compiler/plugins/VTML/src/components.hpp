#ifndef VTML_COMPONENTS_HPP
#define VTML_COMPONENTS_HPP

#include <string>

class VtmlComponents {
public:
    static std::string getBase() {
        return "<style>\n"
               ":root { --bg: #0f172a; --panel: #1e293b; --primary: #38bdf8; --secondary: #818cf8; --text: #f8fafc; --text-muted: #94a3b8; }\n"
               "body { background-color: var(--bg); color: var(--text); font-family: 'Segoe UI', system-ui, sans-serif; padding: 20px; margin: 0; }\n"
               "/* Temel Izgaralar */\n"
               ".page { max-width: 1400px; margin: 0 auto; }\n"
               ".box { background: rgba(30, 41, 59, 0.7); backdrop-filter: blur(10px); padding: 25px; border-radius: 12px; border: 1px solid rgba(255,255,255,0.05); box-shadow: 0 10px 30px rgba(0,0,0,0.5); margin-bottom: 20px; }\n"
               ".center { display: flex; flex-direction: column; align-items: center; text-align: center; }\n"
               ".row { display: flex; flex-direction: row; gap: 15px; align-items: center; width: 100%; flex-wrap: wrap; }\n"
               ".column { display: flex; flex-direction: column; gap: 15px; width: 100%; }\n"
               ".grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(250px, 1fr)); gap: 20px; }\n"
               "/* Tipografi ve Formlar */\n"
               "h1 { color: var(--primary); font-size: 2.2em; margin: 0 0 10px 0; }\n"
               "h2 { color: var(--secondary); font-size: 1.5em; margin: 0 0 10px 0; }\n"
               "p { font-size: 15px; color: var(--text-muted); line-height: 1.6; margin: 0 0 15px 0; }\n"
               ".v-btn { background: linear-gradient(135deg, var(--primary), var(--secondary)); color: #fff; border: none; padding: 10px 24px; font-size: 15px; font-weight: bold; border-radius: 8px; cursor: pointer; transition: 0.3s; }\n"
               ".v-btn:hover { transform: translateY(-2px); box-shadow: 0 8px 25px rgba(56, 189, 248, 0.4); }\n"
               ".v-btn-outline { background: transparent; border: 2px solid var(--primary); color: var(--primary); }\n"
               ".v-input { background: #0b1120; color: #fff; border: 1px solid #334155; padding: 12px 16px; border-radius: 8px; outline: none; width: 100%; max-width: 100%; transition: 0.3s; }\n"
               ".v-input:focus { border-color: var(--primary); box-shadow: 0 0 0 3px rgba(56,189,248,0.2); }\n"
               "/* HTML'DE OLMAYAN GELİŞMİŞ BİLEŞENLER (V-UI) */\n"
               ".v-toggle { position: relative; display: inline-block; width: 50px; height: 26px; }\n"
               ".v-toggle input { opacity: 0; width: 0; height: 0; }\n"
               ".v-slider-round { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #334155; transition: .4s; border-radius: 34px; }\n"
               ".v-slider-round:before { position: absolute; content: ''; height: 18px; width: 18px; left: 4px; bottom: 4px; background-color: white; transition: .4s; border-radius: 50%; }\n"
               ".v-toggle input:checked + .v-slider-round { background-color: var(--primary); }\n"
               ".v-toggle input:checked + .v-slider-round:before { transform: translateX(24px); }\n"
               ".v-terminal { background: #000; color: #0f0; font-family: 'Courier New', monospace; padding: 15px; border-radius: 8px; height: 200px; overflow-y: auto; border: 1px solid #333; width: 100%; box-sizing: border-box; }\n"
               ".v-codeblock { background: #1e1e1e; color: #d4d4d4; font-family: monospace; padding: 15px; border-radius: 8px; border-left: 4px solid var(--secondary); overflow-x: auto; }\n"
               ".v-badge { background: #ef4444; color: white; padding: 2px 8px; border-radius: 12px; font-size: 12px; font-weight: bold; margin-left: 5px; }\n"
               ".v-loader { border: 4px solid rgba(255,255,255,0.1); border-left-color: var(--primary); border-radius: 50%; width: 30px; height: 30px; animation: spin 1s linear infinite; }\n"
               "@keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }\n"
               ".v-progress-bg { width: 100%; background-color: #334155; border-radius: 8px; overflow: hidden; height: 10px; }\n"
               ".v-progress-bar { height: 100%; background-color: var(--primary); width: 0%; transition: width 0.5s; }\n"
               ".v-toast { visibility: hidden; min-width: 250px; background-color: var(--primary); color: #fff; text-align: center; border-radius: 8px; padding: 16px; position: fixed; z-index: 1000; right: 20px; bottom: 30px; font-weight: bold; box-shadow: 0 4px 15px rgba(0,0,0,0.4); }\n"
               ".v-toast.show { visibility: visible; animation: fadein 0.5s, fadeout 0.5s 2.5s; }\n"
               "@keyframes fadein { from {bottom: 0; opacity: 0;} to {bottom: 30px; opacity: 1;} }\n"
               "@keyframes fadeout { from {bottom: 30px; opacity: 1;} to {bottom: 0; opacity: 0;} }\n"
               ".v-upload-zone { border: 2px dashed #475569; border-radius: 12px; padding: 40px; text-align: center; color: var(--text-muted); transition: 0.3s; cursor: pointer; }\n"
               ".v-upload-zone:hover { border-color: var(--primary); background: rgba(56,189,248,0.05); }\n"
               ".v-ai-chat { background: #0b1120; border-radius: 12px; padding: 15px; height: 300px; overflow-y: auto; display: flex; flex-direction: column; gap: 10px; border: 1px solid #334155; }\n"
               ".chat-msg { max-width: 80%; padding: 10px 15px; border-radius: 12px; font-size: 14px; }\n"
               ".msg-user { background: var(--primary); color: #000; align-self: flex-end; border-bottom-right-radius: 0; }\n"
               ".msg-ai { background: #1e293b; color: #fff; align-self: flex-start; border-bottom-left-radius: 0; border: 1px solid #334155; }\n"
               "</style>\n"
               "<script>\n"
               "function v_showToast(msg) { let x = document.getElementById('v-toast-sys'); x.innerText = msg; x.className = 'v-toast show'; setTimeout(function(){ x.className = x.className.replace('show', ''); }, 3000); }\n"
               "function v_termLog(id, msg) { let t = document.getElementById(id); t.innerHTML += '<div>> ' + msg + '</div>'; t.scrollTop = t.scrollHeight; }\n"
               "function v_setProgress(id, val) { document.getElementById(id).style.width = val + '%'; }\n"
               "function v_addMsg(id, sender, msg) { let c = document.getElementById(id); let cls = sender==='user' ? 'msg-user' : 'msg-ai'; c.innerHTML += '<div class=\"chat-msg '+cls+'\">'+msg+'</div>'; c.scrollTop = c.scrollHeight; }\n"
               "</script>\n"
               "<div id='v-toast-sys' class='v-toast'></div>\n"; // Global Toast Container
    }
};

#endif
