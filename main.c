
#include <glib-object.h>

#include "dummy.h"

/**
 * Use GHashTable like Set<Dummy*>
 */
void
use_ghashtable_as_set()
{
	GlsDummy *dummy_1 = gls_dummy_new();
	GlsDummy *dummy_2 = gls_dummy_new();
	GlsDummy *dummy_3 = gls_dummy_new();
	GlsDummy *dummy_4 = gls_dummy_new();
	g_print("\n");

	GHashTable *map = g_hash_table_new_full(
		(GHashFunc)gls_dummy_hash,
		(GEqualFunc)gls_dummy_equal,
		NULL,/*do not unref key while value is unref on hash_tabe_unref*/
		(GDestroyNotify)g_object_unref);

	{
		g_print("g_hash_table_add(#1)\n");
		g_hash_table_add(map, dummy_1);

		g_print("g_hash_table_add(#2)\n");
		g_hash_table_add(map, dummy_2);

		g_print("g_hash_table_add(#3)\n");
		g_hash_table_add(map, dummy_3);

		g_print("g_hash_table_add(#4)\n");
		g_hash_table_add(map, dummy_4);
	}
	
	g_print("\n");
	//g_hash_table_unref(map);
	g_hash_table_ref(map);
	g_hash_table_destroy(map);
}

/**
 * Use GHashTable like Set<Dummy*>
 */
void
use_ghashtable_as_set_with_equal_check()
{
	GlsDummy *dummy_1 = gls_dummy_new_from_hash(10);
	GlsDummy *dummy_2 = gls_dummy_new_from_hash(20);
	GlsDummy *dummy_3 = gls_dummy_new_from_hash(30);
	GlsDummy *dummy_4 = gls_dummy_new_from_hash(10);
	g_print("\n");

	GHashTable *map = g_hash_table_new_full(
		(GHashFunc)gls_dummy_hash,
		(GEqualFunc)gls_dummy_equal,
		NULL,/*do not unref key while value is unref on hash_tabe_unref*/
		(GDestroyNotify)g_object_unref);

	{
		g_print("g_hash_table_add(, #%d)\n", dummy_1->id);
		g_hash_table_add(map, dummy_1);

		g_print("g_hash_table_add(, #%d)\n", dummy_2->id);
		g_hash_table_add(map, dummy_2);

		g_print("g_hash_table_add(, #%d)\n", dummy_3->id);
		g_hash_table_add(map, dummy_3);

		g_print("g_hash_table_add(, #%d)\n", dummy_4->id);
		g_hash_table_add(map, dummy_4);
	}
	
	g_print("\n");
	g_hash_table_unref(map);
	//g_hash_table_ref(map);
	//g_hash_table_destroy(map);
}

void
use_ghashtable_as_set_with_replace_value()
{
	GlsDummy *dummy_1 = gls_dummy_new_from_hash(10);
	GlsDummy *dummy_2 = gls_dummy_new_from_hash(20);
	GlsDummy *dummy_3 = gls_dummy_new_from_hash(30);
	GlsDummy *dummy_4 = gls_dummy_new_from_hash(10);
	g_print("\n");

	GHashTable *map = g_hash_table_new_full(
		(GHashFunc)gls_dummy_hash,
		(GEqualFunc)gls_dummy_equal,
		NULL,/*do not unref key while value is unref on hash_tabe_unref*/
		(GDestroyNotify)g_object_unref);

	{
		gboolean added = FALSE;

		g_print("g_hash_table_add(, #%d)\n", dummy_1->id);
		added = g_hash_table_add(map, dummy_1);
		//if (added) g_object_ref(dummy_1);

		g_print("g_hash_table_add(, #%d)\n", dummy_2->id);
		added = g_hash_table_add(map, dummy_2);
		//if (added) g_object_ref(dummy_2);

		g_print("g_hash_table_add(, #%d)\n", dummy_3->id);
		added = g_hash_table_add(map, dummy_3);
		//if (added) g_object_ref(dummy_3);

		g_print("g_hash_table_add(, #%d)\n", dummy_4->id);
		added = g_hash_table_add(map, dummy_4);// dymmu_1.unref()
		//if (added) { g_object_ref(dummy_4); g_print("\tadded\n");}
	}
/*
	g_print("\n");
	g_object_unref(dummy_1);
	g_object_unref(dummy_2);
	g_object_unref(dummy_3);
	g_object_unref(dummy_4);
*/
	g_print("\n");
	g_hash_table_unref(map);
	//g_hash_table_ref(map);
	//g_hash_table_destroy(map);

}

int
main (int argc, char *argv[])
{
	//use_ghashtable_as_set();
	//use_ghashtable_as_set_with_equal_check();
	use_ghashtable_as_set_with_replace_value();

	g_print("Hello World !\n");
	return 0;
}
