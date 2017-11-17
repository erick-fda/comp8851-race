#include "GlobalPrefs.h"

//Window vars
bool GlobalPrefs::windowFullscreen = false;
int32_t GlobalPrefs::windowWidth = 1280;
int32_t GlobalPrefs::windowHeight = 720;

//Renderer vars
int32_t GlobalPrefs::renderWidth = -1; //-1 means "use window size"
int32_t GlobalPrefs::renderHeight = -1;
int32_t GlobalPrefs::rShadowMapSize = 4096;
float GlobalPrefs::rShadowMapSide = 50.0f;
float GlobalPrefs::rShadowMapNear = 10.0f;
float GlobalPrefs::rShadowMapFar = 20.0f;