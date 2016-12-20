
#include "dummy.h"


static void gls_dummy_class_init(GlsDummyClass *klass);
static void gls_dummy_init(GlsDummy *gobject);

G_DEFINE_TYPE (GlsDummy, gls_dummy, G_TYPE_OBJECT)

static void
gls_dummy_class_init(GlsDummyClass *klass)
{
	GObjectClass *gobject_class;

	gobject_class = (GObjectClass *) klass;


	gls_dummy_parent_class = g_type_class_peek_parent (klass);
}

static void
gls_dummy_init (GlsDummy *object)
{
}

GlsDummy *
gls_dummy_new (void)
{
	return g_object_new (gls_dummy_get_type (),
	                     NULL);
}

