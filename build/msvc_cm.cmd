
set PROJ_DIR=project_msvc
set PROJECT_GEN=Visual Studio 10

@echo ================================
@echo project dir = %PROJ_DIR%
@echo cmake generator = %PROJECT_GEN%
@echo ================================

md %PROJ_DIR%
ERASE /Q %PROJ_DIR%\CMakeCache.txt

cd %PROJ_DIR% && cmake -G "%PROJECT_GEN%" ..\..\src


