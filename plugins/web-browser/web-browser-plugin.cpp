#include <obs-module.h>
#include "web-browser-source.hpp"

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("web-browser", "en-US")
MODULE_EXPORT const char *obs_module_description(void)
{
	return "Web browser source";
}

void RegisterBrowserSource();

bool obs_module_load(void)
{
	RegisterBrowserSource();
	return true;
}
