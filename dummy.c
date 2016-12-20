
#include "dummy.h"

static gint gls_dummy_counter = 0;

static void gls_dummy_class_init(GlsDummyClass *klass);
static void gls_dummy_init(GlsDummy *gobject);

G_DEFINE_TYPE (GlsDummy, gls_dummy, G_TYPE_OBJECT)

static void
gls_dummy_class_object_dispose(GObject *self)
{
	g_print("dummy#%d::dispose\n", GLS_DUMMY(self)->id);
	G_OBJECT_CLASS( gls_dummy_parent_class )->dispose( self );
}

static void
gls_dummy_class_object_finalize(GObject *self)
{
	g_print("dummy#%d::finalize\n", GLS_DUMMY(self)->id);
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
	gls_dummy_counter++;
	object->id = gls_dummy_counter;

	g_print("dummy#%d::init\n", object->id);
}

GlsDummy *
gls_dummy_new (void)
{
	return g_object_new (gls_dummy_get_type (), NULL);
}

guint
gls_dummy_hash(gconstpointer key)
{
	GlsDummy * dummy = GLS_DUMMY(key);
	g_print("dummy#%d::hash\n", dummy->id);
	return dummy->id;
}

