﻿#include "pch.h"
#include "plugin_64.h"

namespace Validator {
	void Validate(DllError e, RunOptions options) {
		if (e.unmatch.code2 > 0 || e.version.code1 > 0 || e.mod.code0 > 0) {
			const DWORD sysDefLcid = ::GetSystemDefaultLCID();

			const WCHAR* message;
			const WCHAR* caption;
			
			switch (sysDefLcid) {
			case MAKELANGID(LANG_JAPANESE, SUBLANG_JAPANESE_JAPAN):
				caption = L"エラー";
				message = L""
					L"このバージョンはまだ日本語化に対応していないため起動できません。\n"
					L"将来、日本語化に対応した際には自動的に起動できるようになります。";
				break;

			case MAKELANGID(LANG_CHINESE_SIMPLIFIED, SUBLANG_CHINESE_SIMPLIFIED):
				caption = L"错误";
				message = L""
					L"Multibyte DLL 尚未支持此游戏版本。\n"
					L"当我发布新的时，它会自动更新。\n"
					L"\n"
					L"DLL宣布页面:\n"
					L"https://github.com/matanki-saito/EU4dll";
				break;


			case MAKELANGID(LANG_CHINESE_TRADITIONAL, SUBLANG_CHINESE_TRADITIONAL):
				caption = L"錯誤";
				message = L""
					L"Multibyte DLL 尚未支持此遊戲版本。\n"
					L"當我發布新的時，它會自動更新。\n"
					L"\n"
					L"DLL宣布頁面:\n"
					L"https://github.com/matanki-saito/EU4dll";
				break;

			case MAKELANGID(LANG_KOREAN, SUBLANG_KOREAN):
				caption = L"오류";
				message = L""
					L"멀티 바이트 DLL은 아직이 게임 버전을 지원하지 않습니다.\n"
					L"새 게시물을 게시하면 자동으로 업데이트됩니다.\n"
					L"\n"
					L"DLL 공지 페이지:\n"
					L"https://github.com/matanki-saito/EU4dll";
				break;

			case MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US):
			default:
				caption = L"ERROR";
				message = L""
					L"Multibyte DLL hasn't supported this game version yet.\n"
					L"It will be updated automatically, when I publish new one.\n"
					L"\n"
					L"DLL announce page:\n"
					L"https://github.com/matanki-saito/EU4dll";
			}

			MessageBoxW(NULL, message, caption, MB_OK);

			BytePattern::LoggingInfo("DLL [NG]");

			exit(-1);
		}
		else {
			BytePattern::LoggingInfo("DLL [OK]");
		}
	}
}