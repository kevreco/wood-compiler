----------------------------------------------------------------
-- Options
----------------------------------------------------------------

newoption {
    trigger = "tests_directory",
	category  = "[Wood] for 'run_tests' action",
	default = "./testsuits",
    description = "Directory with .w files to be tested.",
}

newoption {
    trigger = "tests_exe",
	category  = "[Wood] for 'run_tests' action",
	default = "",
    description = "Executable performing the tests",
}

----------------------------------------------------------------
-- Helpers
----------------------------------------------------------------

function dir_files(dir)
    files { dir .. "/**.hpp", dir .. "/**.cpp", dir .. "/**.h", dir .. "/**.c"}
	filter "system:windows"
		files { dir .. "/**.hpp.win", dir .. "/**.cpp.win", dir .. "/**.h.win", dir .. "/**.c.win"}
	filter "system:unix"
		files { dir .. "/**.hpp.unix", dir .. "/**.cpp.unix", dir .. "/**.h.unix", dir .. "/**.c.unix"}
	filter {} -- clear filter
end

function setup_configuration()
     filter { "configurations:Debug" }
        defines { "DEBUG" }
        symbols "On"
		targetsuffix "debug" -- Add "-debug" to debug versions of files @TODO this does not work for some reason...

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"
		
	filter {} -- clear filter
end

-- =============================================================
-- Build project files
-- =============================================================
-- Example: premake vs2022
-- =============================================================

_location = ".build"; -- location of the generated files (vs, make, etc.)

workspace "wood"
    configurations { "Debug", "Release" }
	location(_location)

project "wood"
    kind "ConsoleApp"
    language "C++"
	location(path.join(_location, "wood")) 
	
	dir_files("./src/cli")
	dir_files("./src/external")
	dir_files("./src/wood")
		
	targetdir ( path.join(_location, "wood", "bin", "%{cfg.buildcfg}") ) -- location of binaries depending of configuration
	objdir ( path.join(_location, "wood", "obj", "%{cfg.buildcfg}") )    -- location of intermediate files depending of configuration
	
	postbuildcommands {
		-- premake5 --file="<my_file> run_tests --tests_directory=<dir> --tests_exe=<exe>"
		string.format(
			' "%s" --file="%s" run_tests --tests_directory="%s" --tests_exe="%s"' ,
			_PREMAKE_COMMAND, _MAIN_SCRIPT, _OPTIONS["tests_directory"],  _OPTIONS["tests_exe"]
		)
	}
	
project "tester"
    kind "ConsoleApp"
    language "C++"
   	location(path.join(_location, "tester")) 
	
	dir_files("./src/external")
	dir_files("./src/wood")
	dir_files("./src/tester")

	targetdir ( path.join(_location, "tester", "bin", "%{cfg.buildcfg}") ) -- location of binaries depending of configuration
	objdir ( path.join(_location, "tester", "obj", "%{cfg.buildcfg}") )    -- location of intermediate files depending of configuration

    filter { "configurations:Debug" }
        defines { "DEBUG" }
        symbols "On"

    filter { "configurations:Release" }
        defines { "NDEBUG" }
        optimize "On"
		
	filter {} -- clear filter
	
-- =============================================================
-- Clean
-- =============================================================
-- Example: premake clean
-- =============================================================

function rmdir(dir)
	if os.isdir(dir) then
		if not os.rmdir(dir) then
			print("cannot remove directory: '" .. dir .. "'")
		end
	end
end

newaction {
	trigger = "clean",
	description = "Wood: Clean generated files and directory",
	execute = function ()
		rmdir(_location)
	end
}
-- =============================================================
-- Run Tests
-- =============================================================
-- Example: premake run_tests
-- =============================================================
	
newaction {
	trigger = "run_tests",
	description = "Wood: Run tests for .w files",
	execute = function ()
		local msg = string.format(
			'@TODO run all tests for directory "%s" using "%s" ',
			_OPTIONS["tests_directory"], _OPTIONS["tests_exe"]
		)
      	print(msg)
	end
}