#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_command(const char *command) {
    int result = system(command);
    if (result == -1) {
        perror("Error executing command");
    }
}

void construct_command(char *command, const char *action, int argc, char *argv[]) {
    if (strcmp(action, "in") == 0 || strcmp(action, "install") == 0) {
        snprintf(command, 512, "winget install %s", argv[2]);
    } else if (strcmp(action, "sw") == 0 || strcmp(action, "show") == 0) {
        snprintf(command, 512, "winget show %s", argv[2]);
    } else if (strcmp(action, "src") == 0 || strcmp(action, "source") == 0) {
        snprintf(command, 512, "winget source %s", argv[2]);
    } else if (strcmp(action, "se") == 0 || strcmp(action, "search") == 0) {
        snprintf(command, 512, "winget search %s", argv[2]);
    } else if (strcmp(action, "ls") == 0 || strcmp(action, "list") == 0) {
        snprintf(command, 512, "winget list");
    } else if (strcmp(action, "up") == 0 || strcmp(action, "upgrade") == 0) {
        snprintf(command, 512, argc < 3 ? "winget upgrade" : "winget upgrade %s", argv[2]);
    } else if (strcmp(action, "ug") == 0) {
        snprintf(command, 512, "winget upgrade --all --include-unknown");
    } else if (strcmp(action, "rm") == 0 || strcmp(action, "uninstall") == 0) {
        snprintf(command, 512, "winget uninstall %s", argv[2]);
    } else if (strcmp(action, "ha") == 0 || strcmp(action, "hash") == 0) {
        snprintf(command, 512, "winget hash %s", argv[2]);
    } else if (strcmp(action, "val") == 0 || strcmp(action, "validate") == 0) {
        snprintf(command, 512, "winget validate %s", argv[2]);
    } else if (strcmp(action, "st") == 0 || strcmp(action, "settings") == 0) {
        snprintf(command, 512, "winget settings");
    } else if (strcmp(action, "ft") == 0 || strcmp(action, "features") == 0) {
        snprintf(command, 512, "winget features");
    } else if (strcmp(action, "ex") == 0 || strcmp(action, "export") == 0) {
        snprintf(command, 512, "winget export");
    } else if (strcmp(action, "im") == 0 || strcmp(action, "import") == 0) {
        snprintf(command, 512, "winget import %s", argv[2]);
    } else if (strcmp(action, "pi") == 0 || strcmp(action, "pin") == 0) {
        snprintf(command, 512, "winget pin %s", argv[2]);
    } else if (strcmp(action, "cfg") == 0 || strcmp(action, "configure") == 0) {
        snprintf(command, 512, "winget configure");
    } else if (strcmp(action, "dw") == 0 || strcmp(action, "download") == 0) {
        snprintf(command, 512, "winget download %s", argv[2]);
    } else if (strcmp(action, "rp") == 0 || strcmp(action, "repair") == 0) {
        snprintf(command, 512, "winget repair %s", argv[2]);
    } else {
        fprintf(stderr, "Unknown command: %s\n", action);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [<package_name>]\n", argv[0]);
        return 1;
    }

    char command[512];
    const char *action = argv[1];
    construct_command(command, action, argc, argv);
    execute_command(command);

    return 0;
}
