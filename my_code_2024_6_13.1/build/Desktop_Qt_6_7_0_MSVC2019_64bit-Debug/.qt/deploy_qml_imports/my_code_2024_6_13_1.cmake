# Auto-generated deploy QML imports script for target "my_code_2024_6_13.1".
# Do not edit, all changes will be lost.
# This file should only be included by qt_deploy_qml_imports().

set(__qt_opts )
if(arg_NO_QT_IMPORTS)
    list(APPEND __qt_opts NO_QT_IMPORTS)
endif()

_qt_internal_deploy_qml_imports_for_target(
    ${__qt_opts}
    IMPORTS_FILE "D:/GitWork/LimouGitWork/limou-c-test-code/my_code_2024_6_13.1/build/Desktop_Qt_6_7_0_MSVC2019_64bit-Debug/src/.qt_plugins/Qt6_QmlPlugins_Imports_my_code_2024_6_13.1.cmake"
    PLUGINS_FOUND __qt_internal_plugins_found
    QML_DIR     "${arg_QML_DIR}"
    PLUGINS_DIR "${arg_PLUGINS_DIR}"
)

if(arg_PLUGINS_FOUND)
    set(${arg_PLUGINS_FOUND} "${__qt_internal_plugins_found}" PARENT_SCOPE)
endif()