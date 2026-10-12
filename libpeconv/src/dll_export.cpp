#include <windows.h>
#include <peconv.h>

extern "C" {

    __declspec(dllexport) BYTE* load_pe_executable2(BYTE* payload_raw, size_t r_size, size_t &v_size) {
        return peconv::load_pe_executable(payload_raw, r_size, v_size);
    }

    __declspec(dllexport) bool set_main_module_in_peb(HMODULE hModule) {
        return peconv::set_main_module_in_peb(hModule);
    }

    __declspec(dllexport) bool load_delayed_imports(BYTE *modulePtr, ULONGLONG moduleBase) {
        return peconv::load_delayed_imports(modulePtr, moduleBase);
    }

    __declspec(dllexport) DWORD get_entry_point_rva(const BYTE *pe_buffer) {
        return peconv::get_entry_point_rva(pe_buffer);
    }

}
