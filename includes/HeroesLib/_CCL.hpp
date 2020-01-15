#pragma once



struct CCL_MASTER
{
	static int& GrvDir;
	static short& enemy2_entry_num_pre;
	static short& enemy_entry_num_pre;
	static int*& chao_entry_list;
	static short& chao_entry_num;
	static int*& wall_entry_list;
	static short& wall_entry_num;
	static int*& item2_entry_list;
	static short& item2_entry_num;
	static int*& item_entry_list;
	static short& item_entry_num;
	static int*& object2_entry_list;
	static short& object2_entry_num;
	static int*& object_entry_list;
	static short& object_entry_num;
	static int*& enemy2_entry_list;
	static short& enemy2_entry_num;
	static int*& enemy_entry_list;
	static short& enemy_entry_num;
	static int*& bullet_entry_list;
	static short*& bullet_entry_num;
	static int*& player_entry_list;
	static short*& player_entry_num;
	static int*& Search;
	static int*& ael_num;
	static int*& around_ring_list;
	static int*& arl_num;
	static int*& around_enemy_list;


	void __cdecl ClearHoming();
};