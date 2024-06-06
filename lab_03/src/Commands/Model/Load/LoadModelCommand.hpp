#ifndef LOADMODELCOMMAND_HPP
#define LOADMODELCOMMAND_HPP

#include <string>

#include "Commands/Model/ModelCommand.hpp"

class LoadModelCommand : public ModelCommand {
public:
    explicit LoadModelCommand(const std::string& path, const std::string& implementation_type);

    void execute() override;
    size_t result() override;
private:
    std::string path, implementation_type;
    size_t id;
};


#endif //LOADMODELCOMMAND_HPP
