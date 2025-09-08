#include <obs-module.h>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("rtmp-output", "en-US")
MODULE_EXPORT const char *obs_module_description(void)
{
	return "RTMP Output";
}

struct rtmp_output {
	obs_output_t *output;
};

static const char *rtmp_output_get_name(void *unused)
{
	UNUSED_PARAMETER(unused);
	return obs_module_text("RTMPOutput");
}

static void *rtmp_output_create(obs_data_t *, obs_output_t *output)
{
	struct rtmp_output *stream = bzalloc(sizeof(struct rtmp_output));
	stream->output = output;
	return stream;
}

static void rtmp_output_destroy(void *data)
{
	struct rtmp_output *stream = data;
	bfree(stream);
}

struct obs_output_info rtmp_output_info = {
	.id = "rtmp_output",
	.flags = OBS_OUTPUT_AV | OBS_OUTPUT_ENCODED,
	.get_name = rtmp_output_get_name,
	.create = rtmp_output_create,
	.destroy = rtmp_output_destroy,
};

bool obs_module_load(void)
{
	obs_register_output(&rtmp_output_info);
	return true;
}
