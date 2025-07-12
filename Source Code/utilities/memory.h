#pragma once

#include <Windows.h>
#include <Tlhelp32.h>
#include <cstdint>
#include <string_view>

class memory
{
private:
	std::uintptr_t process_id = 0;
	void* process_handle = nullptr;

public:
	memory(const std::string_view process_name) noexcept
	{
		::PROCESSENTRY32 entry = { };
		entry.dwSize = sizeof(::PROCESSENTRY32);

		const auto process_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		while (::Process32Next(process_snapshot, &entry))
		{
			if (!process_name.compare(entry.szExeFile))
			{
				process_id = entry.th32ProcessID;
				process_handle = ::OpenProcess(PROCESS_ALL_ACCESS, false, process_id);
				break;
			}
		}

		if (process_snapshot)
		{
			::CloseHandle(process_snapshot);
		}
	}

	~memory()
	{
		if (process_handle) {
			::CloseHandle(process_handle);
		}
	}

	const std::uintptr_t get_modulebase_address(const std::string_view module_name) const noexcept
	{
		::MODULEENTRY32 entry = { };
		entry.dwSize = sizeof(::MODULEENTRY32);

		const auto process_snapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, process_id);

		std::uintptr_t module_baseaddress = 0;

		while (::Module32Next(process_snapshot, &entry))
		{
			if (!module_name.compare(entry.szModule))
			{
				module_baseaddress = reinterpret_cast<std::uintptr_t>(entry.modBaseAddr);
				break;
			}
		}

		if (process_snapshot) {
			::CloseHandle(process_snapshot);
		}

		return module_baseaddress;
	}

	template <typename T>
	constexpr const T read(const std::uintptr_t& address) const noexcept
	{
		T value = {};
		::ReadProcessMemory(process_handle, reinterpret_cast<const void*>(address), &value, sizeof(T), NULL);
		return value;
	}

	template <typename T>
	constexpr void write(const std::uintptr_t& address, const T& value) const noexcept
	{
		::WriteProcessMemory(process_handle, reinterpret_cast<void*>(address), &value, sizeof(T), NULL);
	}
};
