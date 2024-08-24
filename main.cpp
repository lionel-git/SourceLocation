

#include <iostream>
#include <version>

#if defined(__cpp_lib_source_location)
#include <source_location>
#define SOURCE_LOCATION

#if defined(__cpp_lib_stacktrace)
#include <stacktrace>
void log_msg(const std::string& msg, const std::source_location location = std::source_location::current(), const std::stacktrace stacktrace = std::stacktrace::current())
{
    std::cout << "Message with source loc and stacktrace: " << msg << " File: " << location.file_name() << " Line: " << location.line() << std::endl;
    std::cout << "Function: " << location.function_name() << std::endl;
    std::cout << "Stacktrace:\n" << stacktrace << std::endl;
}
#else
void log_msg(const std::string& msg, const std::source_location location& = std::source_location::current())
{
    std::cout << "Message with source loc: " << msg << " File: " << location.file_name() << " Line: " << location.line() << std::endl;
    std::cout << "Function: " << location.function_name() << std::endl;
}
#endif
#else
#define SOURCE_LOCATION , __FILE__, __LINE__
void log_msg(const std::string& msg, const std::string& fileName, int line)
{
    std::cout << "Message without source loc: " << msg << " File: " << fileName << " Line: " << line << std::endl;
}
#endif

int myFunction()
{
    log_msg("MyMessage" SOURCE_LOCATION);
    return 0;
}

int main()
{
    myFunction();
    return 0;
}