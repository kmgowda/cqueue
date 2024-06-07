
# when you are using this file : rename FindBoost-Full.cmake to FindBoost.cmake ; but the download takes time

include(FetchContent)

Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
        boost
        GIT_REPOSITORY "https://github.com/boostorg/boost.git"
        GIT_TAG master
       # GIT_SUBMODULES ${BOOST_REQD_SUBMODULES}
        GIT_PROGRESS TRUE
        CONFIGURE_COMMAND ""  # tell CMake it's not a cmake project
)

FetchContent_MakeAvailable(boost)