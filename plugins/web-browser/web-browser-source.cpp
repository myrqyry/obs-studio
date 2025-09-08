#include "web-browser-source.hpp"

BrowserSource::BrowserSource(obs_data_t *settings, obs_source_t *source)
	: source(source)
{
	Update(settings);
}

BrowserSource::~BrowserSource()
{
}

void BrowserSource::Update(obs_data_t *settings)
{
	if (!settings)
		return;

	width = (int)obs_data_get_int(settings, "width");
	height = (int)obs_data_get_int(settings, "height");
	url = obs_data_get_string(settings, "url");
}

void BrowserSource::Render()
{
}

static void browser_source_get_defaults(obs_data_t *settings)
{
	obs_data_set_default_string(settings, "url", "https://www.google.com");
	obs_data_set_default_int(settings, "width", 800);
	obs_data_set_default_int(settings, "height", 600);
}

static obs_properties_t *browser_source_get_properties(void *)
{
	obs_properties_t *props = obs_properties_create();
	obs_properties_add_text(props, "url", "URL", OBS_TEXT_DEFAULT);
	obs_properties_add_int(props, "width", "Width", 1, 8192, 1);
	obs_properties_add_int(props, "height", "Height", 1, 8192, 1);
	return props;
}

static void *browser_source_create(obs_data_t *settings, obs_source_t *source)
{
	return new BrowserSource(settings, source);
}

static void browser_source_destroy(void *data)
{
	delete static_cast<BrowserSource *>(data);
}

static void browser_source_update(void *data, obs_data_t *settings)
{
	static_cast<BrowserSource *>(data)->Update(settings);
}

static uint32_t browser_source_get_width(void *data)
{
	return static_cast<BrowserSource *>(data)->width;
}

static uint32_t browser_source_get_height(void *data)
{
	return static_cast<BrowserSource *>(data)->height;
}

static void browser_source_render(void *data, gs_effect_t *)
{
	static_cast<BrowserSource *>(data)->Render();
}

void RegisterBrowserSource()
{
	struct obs_source_info info = {};
	info.id = "web_browser_source";
	info.type = OBS_SOURCE_TYPE_INPUT;
	info.output_flags = OBS_SOURCE_VIDEO;
	info.get_name = [](void *) { return "Web Browser"; };
	info.create = browser_source_create;
	info.destroy = browser_source_destroy;
	info.get_defaults = browser_source_get_defaults;
	info.get_properties = browser_source_get_properties;
	info.update = browser_source_update;
	info.get_width = browser_source_get_width;
	info.get_height = browser_source_get_height;
	info.video_render = browser_source_render;

	obs_register_source(&info);
}
