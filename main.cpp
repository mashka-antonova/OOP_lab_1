#include "dependency_provider.h"

int main() {
    DependencyProvider provider;
    Application app = provider.createApplication();
    app.run();
    provider.clean();
    return 0;
}
