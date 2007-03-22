#ifndef _LOOPER_H_
#define _LOOPER_H_

#include <vector>
#include <string>
#include <deque>

#include "bank.h"
#include "audio_engine.h"
#include "persistent_storage.h"

//float time_beats_per_bar = 4.0;
//float time_beat_type = 4.0;
//double time_ticks_per_beat = 1920.0;
//double time_beats_per_minute = 120.0;

class metronome
{
public:
	int32_t get_beat();
	int32_t get_bar();
	int32_t get_tick();
	int32_t get_frame();
};

class looper
{
public:
	void set_banks(size_t);
	void set_audio_engine(audio_engine *);
	void set_persistent_storage(persistent_storage *);
	void read_storage();
	void dirty(); // Mark object (or a child) as `dirty'

	audio_engine *get_audio_engine() { return audio.get(); }
	bank *get_bank(size_t);

	void initialize();
	void run();
	void shutdown();

private:
	std::vector<bank *> banks;
	std::auto_ptr<persistent_storage> storage;
	std::auto_ptr<audio_engine> audio;
};

#endif