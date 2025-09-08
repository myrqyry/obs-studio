#pragma once

#include <obs.hpp>
#include <string>

class BrowserSource {
public:
	BrowserSource(obs_data_t *settings, obs_source_t *source);
	~BrowserSource();

	void Update(obs_data_t *settings);
	void Render();

	obs_source_t *source;
	int width;
	int height;
	std::string url;
};
