#ifndef LOADMANAGER_HPP
#define LOADMANAGER_HPP

#include <string>
#include <memory>

class LoadManager {
public:
    size_t load_wireframe_model(const std::string& path, const std::string& implementation_type);
protected:
    LoadManager() = default;
    LoadManager(const LoadManager& other) = default;
};


#endif //LOADMANAGER_HPP
