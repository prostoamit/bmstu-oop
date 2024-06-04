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
        Objects
        WireframeModel
        Geometry
        Cameras
        Transformations
        Commands
        Visitors
        Scene
        Common
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
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
        WireframeModel/WireframeModelImplementation/Implementation.hpp
        WireframeModel/WireframeModelImplementation/Implementation.cpp
        Geometry/Point.hpp
        Geometry/Point.cpp
        Objects/ObjectComposite.hpp
        Objects/ObjectComposite.cpp
        Visitors/Visitor.hpp
        Visitors/Tranform/TransformVisitor.hpp
        Visitors/Tranform/TransformVisitor.cpp
        Cameras/Camera.hpp
        Cameras/Camera.cpp
        Cameras/ParallelProjectionCamera.hpp
        Cameras/ParallelProjectionCamera.cpp
        Transformations/Transformer.hpp
        Transformations/Rotation/Rotate.cpp
        Transformations/Rotation/Rotate.hpp
        Geometry/TransformationMatrix.cpp
        Geometry/TransformationMatrix.hpp
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
        Managers/SceneManager.cpp
        Managers/SceneManager.hpp
        Scene/Scene.cpp
        Scene/Scene.hpp
        Geometry/Vector.cpp
        Geometry/Vector.hpp
        Geometry/Point2D.cpp
        Geometry/Point2D.hpp
        Common/Container.inl
        Common/Container.hpp
        WireframeModel/WireframeModelImplementation/Edge.cpp
        WireframeModel/WireframeModelImplementation/Edge.hpp
        WireframeModel/WireframeModelImplementation/VerticesPairs/VerticesPairs.cpp
        WireframeModel/WireframeModelImplementation/VerticesPairs/VerticesPairs.hpp
        WireframeModel/WireframeModelImplementation/Matrix/Matrix.cpp
        WireframeModel/WireframeModelImplementation/Matrix/Matrix.hpp
        WireframeModel/WireframeModelImplementation/AdjacencyList/AdjacencyList.cpp
        WireframeModel/WireframeModelImplementation/AdjacencyList/AdjacencyList.hpp
        Transformations/Move/Move.cpp
        Transformations/Move/Move.hpp
        Transformations/Scale/Scale.cpp
        Transformations/Scale/Scale.hpp
        Transformations/TransformerCreator.cpp
        Transformations/TransformerCreator.hpp
        Transformations/Factories/MoveFactory.cpp
        Transformations/Factories/MoveFactory.hpp
        Transformations/Factories/Factory.hpp
        Transformations/Factories/ScaleFactory.cpp
        Transformations/Factories/ScaleFactory.hpp
        Visitors/Draw/DrawVisitor.cpp
        Visitors/Draw/DrawVisitor.hpp
        Drawer/ScreenCleaner/ScreenCleaner.cpp
        Drawer/ScreenCleaner/ScreenCleaner.hpp
        Drawer/Line/LineDrawer.cpp
        Drawer/Line/LineDrawer.hpp
        Drawer/Line/QtLineDrawer.cpp
        Drawer/Line/QtLineDrawer.hpp
        Drawer/ShapeDrawerFactory.cpp
        Drawer/ShapeDrawerFactory.hpp
        Drawer/QtShapeDrawerFactory.cpp
        Drawer/QtShapeDrawerFactory.hpp
        Drawer/ScreenCleaner/QtScreenCleaner.cpp
        Drawer/ScreenCleaner/QtScreenCleaner.hpp
)

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

target_link_libraries(src PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

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
