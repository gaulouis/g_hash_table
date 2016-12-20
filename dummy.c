
#include "dummy.h"

static gint gls_dummy_counter = 0;

static void gls_dummy_class_init(GlsDummyClass *klass);
static void gls_dummy_init(GlsDummy *gobject);

G_DEFINE_TYPE (GlsDummy, gls_dummy, G_TYPE_OBJECT)

static void
gls_dummy_class_object_dispose(GObject *self)
{
	g_print("dummy::dispose(#%d)\n", GLS_DUMMY(self)->id);
	G_OBJECT_CLASS( gls_dummy_parent_class )->dispose( self );
}

static void
gls_dummy_class_object_finalize(GObject *self)
{
	g_print("\tdummy::finalize(#%d)\n", GLS_DUMMY(self)->id);
	G_OBJECT_CLASS( gls_dummy_parent_class )->finalize( self );
}

static void
gls_dummy_class_init(GlsDummyClass *klass)
{
	GObjectClass *gobject_class;
	gobject_class = (GObjectClass *) klass;

	gobject_class->dispose = gls_dummy_class_object_dispose;
	gobject_class->finalize = gls_dummy_class_object_finalize;
}

static void
gls_dummy_init (GlsDummy *object)
{
	object->id = ++gls_dummy_counter;
	g_print("dummy::init(#%d)\n", object->id);
}

GlsDummy*
gls_dummy_new (void)
{
	GlsDummy* dummy = g_object_new (gls_dummy_get_type (), NULL);
	dummy->hash = dummy->id * 10;
	return dummy;
}

GlsDummy*
gls_dummy_new_from_hash(guint hash)
{
	GlsDummy* dummy = g_object_new (gls_dummy_get_type (), NULL);
	dummy->hash = hash;
	return dummy;
}

guint
gls_dummy_hash(gconstpointer key)
{
	GlsDummy * dummy = GLS_DUMMY(key);
	g_print("\tdummy::hash(#%d):%d\n", dummy->id, dummy->hash);
	return dummy->hash;
}

gboolean
gls_dummy_equal(gconstpointer a, gconstpointer b)
{
	gboolean equal = GLS_DUMMY(a)->hash == GLS_DUMMY(b)->hash;
	g_print("\tdummy::equal(#%d, #%d):%s\n", GLS_DUMMY(a)->id, GLS_DUMMY(b)->id, equal ? "true": "false");
	return equal;
}

