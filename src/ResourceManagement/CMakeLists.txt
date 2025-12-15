# Resource Management module
add_library(ResourceManagement)

# --- sources ---
target_sources(ResourceManagement PRIVATE
        #CPPS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Reservation.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Resource.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceTypes/LabEquipment.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceTypes/SportCourt.cpp

        #HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Reservation.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Resource.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceTypes/LabEquipment.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceTypes/SportCourt.cpp
)

# --- INCLUDES ---

target_include_directories(ResourceManagement
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ResourceTypes
)
