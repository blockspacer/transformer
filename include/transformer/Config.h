#ifndef __TRANSFORMER_CONFIG_H__
#define __TRANSFORMER_CONFIG_H__

#include <vector>
#include <filesystem>

namespace transformer
{

class Config
{
private:
	std::filesystem::path m_tmpl_file_path;
	std::filesystem::path m_src_file_path;
	std::filesystem::path m_out_file_path;

	std::vector<std::pair<std::string_view, std::string_view>> m_tmpl_args;

	bool m_no_strip_first_newline = false;
	bool m_strip_beg_whitespaces = false;

	int                m_compiler_argc;
	const char* const* m_compiler_argv;

	static void print_help();

public:
	Config(int argc, char* const argv[]);

	const auto& tmpl_file_path() const noexcept { return m_tmpl_file_path; }
	const auto& src_file_path() const noexcept { return m_src_file_path; }
	const auto& out_file_path() const noexcept { return m_out_file_path; }

	const auto& tmpl_args() const noexcept { return m_tmpl_args; }

	bool no_strip_first_newline() const noexcept { return m_no_strip_first_newline; }
	bool strip_beg_whitespaces() const noexcept { return m_strip_beg_whitespaces; }

	auto compiler_argc() const noexcept { return m_compiler_argc; }
	auto compiler_argv() const noexcept { return m_compiler_argv; }
};

}

#endif // !__TRANSFORMER_CONFIG_H__