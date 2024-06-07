cmake_minimum_required(VERSION 3.5)

project(src VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
        .
)

set(PROJECT_SOURCES
        main.cpp
        QtInterface/mainwindow.cpp
        QtInterface/mainwindow.h
        QtInterface/mainwindow.ui
        Objects/Object.hpp
        Objects/Object.cpp
        Objects/Composite/CompositeObject.hpp
        Objects/Composite/CompositeObject.cpp
        Objects/Visible/VisibleObject.hpp
        Objects/Visible/VisibleObject.cpp
        Objects/Invisible/InvisibleObject.hpp
        Objects/Invisible/InvisibleObject.cpp
        Objects/Visible/Models/Model.hpp
        Objects/Visible/Models/Model.cpp
        Objects/CareTaker/ObjectCareTaker.cpp
        Objects/CareTaker/ObjectCareTaker.hpp
        Objects/CareTaker/ObjectMemento.cpp
        Objects/CareTaker/ObjectMemento.hpp
        Objects/Visible/Models/WireframeModel/WireframeModel.hpp
        Objects/Visible/Models/WireframeModel/WireframeModel.cpp
        Objects/Visible/Models/WireframeModel/Implementation/WireframeModelImplementation.hpp
        Objects/Visible/Models/WireframeModel/Implementation/WireframeModelImplementation.cpp
        Objects/Visible/Models/WireframeModel/Implementation/Edge.cpp
        Objects/Visible/Models/WireframeModel/Implementation/Edge.hpp
        Objects/Visible/Models/WireframeModel/Implementation/VerticesPairs/VerticesPairs.cpp
        Objects/Visible/Models/WireframeModel/Implementation/VerticesPairs/VerticesPairs.hpp
        Objects/Visible/Models/WireframeModel/Implementation/Matrix/Matrix.cpp
        Objects/Visible/Models/WireframeModel/Implementation/Matrix/Matrix.hpp
        Objects/Visible/Models/WireframeModel/Implementation/AdjacencyList/AdjacencyList.cpp
        Objects/Visible/Models/WireframeModel/Implementation/AdjacencyList/AdjacencyList.hpp
        Geometry/Point.hpp
        Geometry/Point.cpp
        Geometry/TransformationMatrix.cpp
        Geometry/TransformationMatrix.hpp
        Geometry/Vector.cpp
        Geometry/Vector.hpp
        Geometry/Point2D.cpp
        Geometry/Point2D.hpp
        Visitors/Visitor.hpp
        Visitors/Transform/TransformVisitor.hpp
        Visitors/Transform/TransformVisitor.cpp
        Visitors/Draw/DrawVisitor.cpp
        Visitors/Draw/DrawVisitor.hpp
        Objects/Invisible/Cameras/Camera.hpp
        Objects/Invisible/Cameras/Camera.cpp
        Objects/Invisible/Cameras/ParallelProjectionCamera/ParallelProjectionCamera.hpp
        Objects/Invisible/Cameras/ParallelProjectionCamera/ParallelProjectionCamera.cpp
        Transformations/Transformer.hpp
        Transformations/Rotation/Rotate.cpp
        Transformations/Rotation/Rotate.hpp
        Transformations/Move/Move.cpp
        Transformations/Move/Move.hpp
        Transformations/Scale/Scale.cpp
        Transformations/Scale/Scale.hpp
        Commands/Command.hpp
        Commands/Model/ModelCommand.hpp
        Commands/History/HistoryCommand.hpp
        Commands/Camera/CameraCommand.hpp
        Commands/Scene/SceneCommand.hpp
        Managers/ManagerSolution.cpp
        Managers/ManagerSolution.hpp
        Managers/HistoryManager/HistoryManager.cpp
        Managers/HistoryManager/HistoryManager.hpp
        Managers/SceneManager/SceneManager.cpp
        Managers/SceneManager/SceneManager.hpp
        Scene/Scene.cpp
        Scene/Scene.hpp
        Common/Container.inl
        Common/Container.hpp
        Common/Concepts.hpp
        Drawer/ScreenCleaner/ScreenCleaner.hpp
        Drawer/Line/LineDrawer.hpp
        Drawer/Line/QtLineDrawer/QtLineDrawer.cpp
        Drawer/Line/QtLineDrawer/QtLineDrawer.hpp
        Creators/DrawerFactories/ShapeDrawerFactory.hpp
        Creators/DrawerFactories/QtDrawerFactory/QtShapeDrawerFactory.cpp
        Creators/DrawerFactories/QtDrawerFactory/QtShapeDrawerFactory.hpp
        Drawer/ScreenCleaner/QtScreenCleaner/QtScreenCleaner.cpp
        Drawer/ScreenCleaner/QtScreenCleaner/QtScreenCleaner.hpp
        Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilder.cpp
        Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilder.hpp
        Objects/Visible/Models/WireframeModel/Sources/WireframeModelSource.hpp
        Objects/Visible/Models/WireframeModel/Sources/TxtFile/WireframeModelSourceTxt.cpp
        Objects/Visible/Models/WireframeModel/Sources/TxtFile/WireframeModelSourceTxt.hpp
        Creators/Objects/Models/WireframeModel/Builders/VerticesPairs/VerticesPairsWireframeModelBuilder.cpp
        Creators/Objects/Models/WireframeModel/Builders/VerticesPairs/VerticesPairsWireframeModelBuilder.hpp
        Creators/Objects/Models/WireframeModel/Builders/Matrix/MatrixWireframeModelBuilder.cpp
        Creators/Objects/Models/WireframeModel/Builders/Matrix/MatrixWireframeModelBuilder.hpp
        Creators/Objects/Models/WireframeModel/Builders/AdjacencyList/AdjacencyListWireframeModelBuilder.cpp
        Creators/Objects/Models/WireframeModel/Builders/AdjacencyList/AdjacencyListWireframeModelBuilder.hpp
        Creators/Transformations/TransformationCreator.hpp
        Creators/Transformations/TransformationSolution.cpp
        Creators/Transformations/TransformationSolution.hpp
        Creators/Objects/Models/WireframeModel/Sources/WireframeModelSourceCreator.hpp
        Creators/Objects/Models/WireframeModel/Sources/Txt/TxtWireframeModelSourceCreator.cpp
        Creators/Objects/Models/WireframeModel/Sources/Txt/TxtWireframeModelSourceCreator.hpp
        Creators/Objects/Models/WireframeModel/Sources/WireframeModelSourceSolution.cpp
        Creators/Objects/Models/WireframeModel/Sources/WireframeModelSourceSolution.hpp
        Creators/Objects/Models/WireframeModel/WireframeModelCreator.cpp
        Creators/Objects/Models/WireframeModel/WireframeModelCreator.hpp
        Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilderSolution.cpp
        Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilderSolution.hpp
        Creators/Objects/Models/WireframeModel/Builders/AdjacencyList/AdjacencyListWireframeModelBuilderCreator.cpp
        Creators/Objects/Models/WireframeModel/Builders/AdjacencyList/AdjacencyListWireframeModelBuilderCreator.hpp
        Creators/Objects/Models/WireframeModel/Builders/WireframeModelBuilderCreator.hpp
        Creators/Objects/Models/WireframeModel/Builders/Matrix/MatrixWireframeModelBuilderCreator.cpp
        Creators/Objects/Models/WireframeModel/Builders/Matrix/MatrixWireframeModelBuilderCreator.hpp
        Creators/Objects/Models/WireframeModel/Builders/VerticesPairs/VerticesPairsWireframeModelBuilderCreator.cpp
        Creators/Objects/Models/WireframeModel/Builders/VerticesPairs/VerticesPairsWireframeModelBuilderCreator.hpp
        Transformations/Transformer.cpp
        Creators/Transformations/MoveCreator/MoveCreator.cpp
        Creators/Transformations/MoveCreator/MoveCreator.hpp
        Creators/Transformations/MoveCreator/MoveCreator.hpp
        Creators/Transformations/ScaleCreator/ScaleCreator.cpp
        Creators/Transformations/ScaleCreator/ScaleCreator.hpp
        Creators/Transformations/RotateCreator/RotateCreator.cpp
        Creators/Transformations/RotateCreator/RotateCreator.hpp
        Managers/LoadManager/LoadManager.cpp
        Managers/LoadManager/LoadManager.hpp
        Managers/TransformManager/TransformManager.cpp
        Managers/TransformManager/TransformManager.hpp
        Managers/DrawManager/DrawManager.cpp
        Managers/DrawManager/DrawManager.hpp
        Creators/Managers/History/HistoryManagerCreator.cpp
        Creators/Managers/History/HistoryManagerCreator.hpp
        Creators/Managers/Scene/SceneManagerCreator.cpp
        Creators/Managers/Scene/SceneManagerCreator.hpp
        Creators/Managers/Transform/TransformManagerCreator.cpp
        Creators/Managers/Transform/TransformManagerCreator.hpp
        Creators/Managers/Draw/DrawManagerCreator.cpp
        Creators/Managers/Draw/DrawManagerCreator.hpp
        Creators/Managers/Load/LoadManagerCreator.cpp
        Creators/Managers/Load/LoadManagerCreator.hpp
        Managers/CameraManager/CameraManager.cpp
        Managers/CameraManager/CameraManager.hpp
        Scene/Cameras.cpp
        Scene/Cameras.hpp
        Creators/Managers/Camera/CameraManagerCreator.cpp
        Creators/Managers/Camera/CameraManagerCreator.hpp
        Creators/Objects/Cameras/CameraCreator.cpp
        Creators/Objects/Cameras/CameraCreator.hpp
        Creators/Objects/Cameras/ParallelProjection/ParallelProjectionCameraCreator.cpp
        Creators/Objects/Cameras/ParallelProjection/ParallelProjectionCameraCreator.hpp
        Creators/Objects/Cameras/CameraSolution.cpp
        Creators/Objects/Cameras/CameraSolution.hpp
        Commands/Model/Move/ModelMoveCommand.cpp
        Commands/Model/Move/ModelMoveCommand.hpp
        Commands/Command.cpp
        Commands/Model/Scale/ModelScaleCommand.cpp
        Commands/Model/Scale/ModelScaleCommand.hpp
        Commands/Model/Rotate/ModelRotateCommand.cpp
        Commands/Model/Rotate/ModelRotateCommand.hpp
        Commands/Model/Load/LoadModelCommand.cpp
        Commands/Model/Load/LoadModelCommand.hpp
        Commands/Camera/Add/AddCameraCommand.cpp
        Commands/Camera/Add/AddCameraCommand.hpp
        Commands/Camera/Remove/RemoveCameraCommand.cpp
        Commands/Camera/Remove/RemoveCameraCommand.hpp
        Commands/Camera/Set/SetCameraCommand.cpp
        Commands/Camera/Set/SetCameraCommand.hpp
        Commands/Camera/Move/MoveCameraCommand.cpp
        Commands/Camera/Move/MoveCameraCommand.hpp
        Commands/Camera/Rotate/RotateCameraCommand.cpp
        Commands/Camera/Rotate/RotateCameraCommand.hpp
        Commands/Facade.cpp
        Commands/Facade.hpp
        Commands/Camera/CameraCommands.hpp
        Commands/Model/ModelCommands.hpp
        Commands/Commands.hpp
        QtInterface/AppLogic/Logic.cpp
        QtInterface/AppLogic/Logic.hpp
        Commands/Model/Remove/RemoveModelCommand.cpp
        Commands/Model/Remove/RemoveModelCommand.hpp
        Commands/Scene/Draw/DrawSceneCommand.cpp
        Commands/Scene/Draw/DrawSceneCommand.hpp
        Commands/Scene/SceneCommands.hpp
        Commands/AllModels/Move/AllModelsMoveCommand.cpp
        Commands/AllModels/Move/AllModelsMoveCommand.hpp
        Commands/AllModels/AllModelsCommand.hpp
        Commands/AllModels/Rotate/AllModelsRotateCommand.cpp
        Commands/AllModels/Rotate/AllModelsRotateCommand.hpp
        Commands/AllModels/Scale/AllModelsScaleCommand.cpp
        Commands/AllModels/Scale/AllModelsScaleCommand.hpp
        Commands/AllModels/AllModelsCommands.hpp
        Exceptions/Exception.cpp
        Exceptions/Exception.hpp
        Exceptions/Scene/NoModel/NoModelException.cpp
        Exceptions/Scene/NoModel/NoModelException.hpp
        Commands/Scene/SetActiveModel/SetActiveModelCommand.cpp
        Commands/Scene/SetActiveModel/SetActiveModelCommand.hpp
        QtInterface/AppLogic/Data.cpp
        QtInterface/AppLogic/Data.hpp
        Objects/Visible/Models/WireframeModel/Sources/String/WireframeModelSourceString.cpp
        Objects/Visible/Models/WireframeModel/Sources/String/WireframeModelSourceString.hpp
        Objects/Visible/Models/WireframeModel/Sources/String/WireframeModelSourceString.hpp
        Creators/Objects/Models/WireframeModel/Sources/String/StringWireframeModelSourceCreator.cpp
        Creators/Objects/Models/WireframeModel/Sources/String/StringWireframeModelSourceCreator.hpp
)

# Add GoogleTest
find_package(GTest REQUIRED)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(src
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET src APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(src SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(src
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(src PRIVATE Qt${QT_VERSION_MAJOR}::Widgets gsl ${GTEST_LIBRARIES} pthread)

set_target_properties(src PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS src
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(src)
endif()
