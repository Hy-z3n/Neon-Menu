#include "pch.h"
#include "Bools.h"
#include <imgui-hook.hpp>
#include <imgui/imgui.h>

static float fSpeed;

//static float Color[] {1.0f, 1.0f, 1.0f, 1.0f};

void RenderMenu()
{    
    if(fSpeed <= 0)
    {
        fSpeed = 1;
    }
    ImGuiHook::setKeybind(VK_TAB);
    if(ShowMenu)
    {
        ImGui::Begin("Mod Menu");
        if(ImGui::Button("Credits"))
        {
            gd::FLAlertLayer::create(nullptr, "Credits", "OK", nullptr, "Mod Created By <cy>NightBot339</c>\n<cc>I'm Not Responsible for You Getting Banned</c>")->show();
        }
        if(ImGui::Checkbox("Noclip", &Noclipped))
        {
            if(Noclipped)
            {
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xEB\x37", 2, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x8A\x80", 2, NULL);
            }
        }
        if(ImGui::Checkbox("Accurate Precentage", &ApBar))
        {
            if(ApBar)
            {
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x32\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x30\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
            }
        }
        if(ImGui::Checkbox("Hide Progress Bar", &Hpp))
        {
            if(Hpp)
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCE89), "\x0F\x57\xC0\x90\x90\x90", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF38), "\x0D", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF6B), "\x3F", 1, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCE89), "\xF3\x0F\x10\x44\x24\x48", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF38), "\x05", 1, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF6B), "\x00", 1, NULL);
            }
        }
        if(ImGui::Checkbox("Hide Attempts", &Hatt))
        {
            if(Hatt)
            {
                 WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2D83B8), "\x01", 1, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2D83B8), "\x41", 1, NULL);
            }
        }
        if(ImGui::Checkbox("Practice Music Hack", &MusicHack))
        {
            if(MusicHack)
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x90\x90\x90\x90\x90\x90", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x90\x90", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x90\x90", 2, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x0F\x85\xF7\x00\x00\x00", 6, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x75\x41", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x75\x3E", 2, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x75\x0C", 2, NULL);
            }
        }
        if(ImGui::Checkbox("Safe Mode", &SafeMode))
        {
            if(ImGui::IsMouseHoveringRect)
            {
                ImGui::Text("Test");
            }
            if(SafeMode)
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\xE9\x9A\x01\x00\x00\x90\x90", 7, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\x80\xBB\x94\x04\x00\x00\x00", 7, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\xE9\x13\x06\x00\x00\x90\x90", 7, NULL);
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\x83\xB9\x64\x03\x00\x00\x01", 7, NULL);
            }
        }        
        if(ImGui::Checkbox("Instant Respawn", &InstRespawn))
        {
            if(InstRespawn)
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A677), "\xE8", 1, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A677), "\xD8", 1, NULL);
            }
        }       
        if(ImGui::Checkbox("No Death Effect", &NoBlood))
        {
             if(NoBlood)
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\xC3", 1, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\x55", 1, NULL);
            }
        }
        if(ImGui::Checkbox("Same Dual Color", &Twins))
        {
            if(Twins)
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FC142), "\x8B\x88\x3C\x02\x00\x00\x2B\x88\x40\x02\x00\x00", 12, NULL);
            }
            else
            {
                WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FC142), "\x8B\x88\x48\x02\x00\x00\x2B\x88\x4C\x02\x00\x00", 12, NULL);
            }
        }
        if(ImGui::SliderFloat("Speed", &fSpeed, 0.1f, 2.0f))
        {
            CCDirector::sharedDirector()->getScheduler()->setTimeScale(fSpeed);
        }   
        ImGui::Text("Accurate Speed Hack");
        if(ImGui::InputFloat((""), &fSpeed, 0.01f, 2.0f, "%.3f"))
        {
             CCDirector::sharedDirector()->getScheduler()->setTimeScale(fSpeed);
        } 
        //if(ImGui::ColorPicker3("Menu Color", Color, 0))
        //{

        //}
        ImGui::End();
    }
}   
DWORD WINAPI my_thread(void* hModule) 
{
    ImGuiHook::setRenderFunction(RenderMenu);
    ImGuiHook::setToggleCallback([]()
    {
        ShowMenu = !ShowMenu;
    });

    if(MH_Initialize() == MH_OK)
    {
        ImGuiHook::setupHooks([](void* Target, void* Hook, void** IdkWhatToNameThis)
        {
            MH_CreateHook(Target, Hook, IdkWhatToNameThis);
            MH_EnableHook(MH_ALL_HOOKS);
        });
    }
    else 
    {
        FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(hModule), 0);
    }
    return true;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
 {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) 
    {
        // Creating a thread
        CreateThread(0, 0x1000, my_thread, hModule, 0, 0);
    }
    return TRUE;
}