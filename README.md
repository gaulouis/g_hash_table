# Example of GHashTable as Set map


$ ./main
dummy::init(#1)
dummy::init(#2)
dummy::init(#3)
dummy::init(#4)

g_hash_table_add(, #1)
	dummy::hash(#1):10
g_hash_table_add(, #2)
	dummy::hash(#2):20
g_hash_table_add(, #3)
	dummy::hash(#3):30
g_hash_table_add(, #4)
	dummy::hash(#4):10
	dummy::equal(#1, #4):true
dummy::dispose(#1)
	dummy::finalize(#1)

dummy::dispose(#3)
	dummy::finalize(#3)
dummy::dispose(#4)
	dummy::finalize(#4)
dummy::dispose(#2)
	dummy::finalize(#2)

