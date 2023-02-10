#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fstream>

int main() {

    std::cout << "Public IP Address: " << std::endl;
    system("curl ifconfig.me");


    std::cout << std::endl;


    char hostname[1024];
    gethostname(hostname, 1024);
    std::cout << "Hostname: " << hostname << std::endl;

    long hostid = gethostid();
    char *user = getlogin();
    char *home = getenv("HOME");
    char *shell = getenv("SHELL");
    char *path = getenv("PATH");


    std::cout << "PATH: ";
    for (int i = 0; i < strlen(path); i++) {
        if (path[i] == ':') {
            std::cout << std::endl;
        } else {
            std::cout << path[i];
        }
    }
    std::cout << std::endl;

    std::cout << "Shell: " << shell << std::endl;
    std::cout << "HOME: " << home << std::endl;
    std::cout << "Username: " << user << std::endl;
    std::cout << "Host ID: " << hostid << std::endl;

    long pagesize = sysconf(_SC_PAGE_SIZE);
    std::cout << "Page Size: " << pagesize / 1024 << " KB" << std::endl;

    long nprocessors = sysconf(_SC_NPROCESSORS_ONLN);
    std::cout << "Number of processors: " << nprocessors << std::endl;

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    std::cout << "Working Directory: " << cwd << std::endl;

    long ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
    std::cout << "RAM: " << ram / 1024 / 1024 << " MB" << std::endl;

    std::cout << "CPU Info: " << std::endl;
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    while (std::getline(cpuinfo, line)) {
        std::cout << line << std::endl;
    }

    std::cout << "OS Info: " << std::endl;
    std::ifstream osinfo("/etc/os-release");
    while (std::getline(osinfo, line)) {
        std::cout << line << std::endl;
    }

    std::cout << "Password Info: " << std::endl;
    std::ifstream passwd("/etc/passwd");

    while (std::getline(passwd, line)) {
        std::cout << line << std::endl;
    }

    
    std::cout << "Domain Info: " << std::endl;
    std::ifstream domain("/etc/resolv.conf");
    std::getline(domain, line);
    while (std::getline(domain, line)) {
        std::cout << line << std::endl;
    }



    return 0;
}