cmake_minimum_required(VERSION 3.28)
project(lab_03)

set(CMAKE_CXX_STANDARD 23)

include_directories(
        Objects
        WireframeModel
        geometry
        Cameras
        Transformations
        Commands
        Commands/ModelCommands
        Commands/CameraCommands
        Commands/SceneCommands
        Commands/HistoryCommands
)

add_executable(lab_03 main.cpp
        Objects/Object.hpp
        Objects/Object.cpp
        Objects/VisibleObject.hpp
        Objects/VisibleObject.cpp
        Objects/InvisibleObject.hpp
        Objects/InvisibleObject.cpp
        Objects/Model.hpp
        Objects/Model.cpp
        WireframeModel/WireframeModel.hpp
        WireframeModel/WireframeModel.cpp
        WireframeModel/WireframeModelImplementation.hpp
        WireframeModel/WireframeModelImplementation.cpp
        geometry/Point.hpp
        geometry/Point.cpp
        Objects/ObjectComposite.hpp
        Objects/ObjectComposite.cpp
        Visitors/Visitor.hpp
        Visitors/TransformVisitor.hpp
        Visitors/TransformVisitor.cpp
        Cameras/Camera.hpp
        Cameras/Camera.cpp
        Cameras/ParallelProjectionCamera.hpp
        Cameras/ParallelProjectionCamera.cpp
        Transformations/Transformer.hpp
        Transformations/RotateTransformer.cpp
        Transformations/RotateTransformer.hpp
        geometry/TransformationMatrix.cpp
        geometry/TransformationMatrix.hpp
        Commands/Command.hpp
        Commands/ModelCommands/ModelCommand.hpp
        Commands/HistoryCommands/HistoryCommand.hpp
        Commands/CameraCommands/CameraCommand.hpp
        Commands/SceneCommands/SceneCommand.hpp
        Managers/ManagerSolution.cpp
        Managers/ManagerSolution.hpp
        Managers/HistoryManager.cpp
        Managers/HistoryManager.hpp
        Objects/CareTaker/ObjectCareTaker.cpp
        Objects/CareTaker/ObjectCareTaker.hpp
        Objects/CareTaker/ObjectMemento.cpp
        Objects/CareTaker/ObjectMemento.hpp
)
