find_package(Qt5 COMPONENTS                  # 查找 Qt5 的如下库
        Core
        Gui
        Widgets
        REQUIRED)

add_subdirectory(Vendors)
add_subdirectory(Runtime)
add_subdirectory(App)