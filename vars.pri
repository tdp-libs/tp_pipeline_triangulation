TARGET = tp_pipeline_triangulation
TEMPLATE = lib

DEFINES += TP_PIPELINE_TRIANGULATION_LIBRARY

SOURCES += src/Globals.cpp
HEADERS += inc/tp_pipeline_triangulation/Globals.h

#-- Delegates --------------------------------------------------------------------------------------
SOURCES += src/step_delegates/ColorizePolygonsStepDelegate.cpp
HEADERS += inc/tp_pipeline_triangulation/step_delegates/ColorizePolygonsStepDelegate.h

