#include "settings.h"

#include <stdexcept>

#include "externallib/externallib.h"

void settings_t::load_settings()
{
    DWORD dwAttrib = GetFileAttributesW(config_name.data());

    if((dwAttrib == INVALID_FILE_ATTRIBUTES || (dwAttrib & FILE_ATTRIBUTE_DIRECTORY)))
    {
        CreateFileW(config_name.data(),
            GENERIC_WRITE,
            FILE_SHARE_WRITE,
            nullptr,
            CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            nullptr);
        save_settings();
        return;
    }

#define SETT(val) val = get_value(L"AIM", L ## #val, val)
    SETT(aim);
    aim_scope = static_cast<scope_t>(get_value(L"AIM", L"aim_scope", static_cast<float>(aim_scope)));
    SETT(aim_max_distance);
    SETT(aim_lost_distance);
#undef SETT

#define SETT(val) val = get_value(L"ESP", L ## #val, val)
    SETT(esp);
    SETT(esp_max_distance);
    SETT(esp_with_health);
#undef SETT
}

void settings_t::save_settings()
{
#define SETT(val) save_value(L"AIM", L ## #val, val)
    SETT(aim);
    save_value(L"AIM", L"aim_scope", static_cast<int>(aim_scope));
    SETT(aim_max_distance);
    SETT(aim_lost_distance);
#undef SETT

#define SETT(val) save_value(L"ESP", L ## #val, val)
    SETT(esp);
    SETT(esp_max_distance);
    SETT(esp_with_health);
#undef SETT
}

float settings_t::get_value(std::wstring_view settings_name, std::wstring_view key_name, float value)
{
    WCHAR buff[255];
    GetCurrentDirectoryW(255, buff);

    auto size = GetPrivateProfileStringW(settings_name.data()
                                         , key_name.data()
                                         , L""
                                         , buff, 255
                                         , (std::wstring(buff) + L"\\" + config_name).data() ) ;

    if (size == 0)
    {
        save_value(settings_name, key_name, value);
        std::cerr << "settings_t::get_value(): GetPrivateProfileStringW failed!" << std::endl;
        return value;
    }

    return static_cast<float>(_wtof(buff));
}

void settings_t::save_value(std::wstring_view settings_name, std::wstring_view key_name, float value)
{
    WCHAR buff[255];
    GetCurrentDirectoryW(255, buff);

    auto ok = WritePrivateProfileStringW(settings_name.data()
                                         , key_name.data()
                                         , std::to_wstring(value).data()
                                         , (std::wstring(buff) + L"\\" + config_name).data() );
    if (!ok)
    {
        std::cerr << "settings_t::save_value(): WritePrivateProfileStringW failed!" << std::endl;
        return;
    }
}
