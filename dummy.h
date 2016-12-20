
#ifndef __GLS_DUMMY_H__
#define __GLS_DUMMY_H__

#include <glib-object.h>


G_BEGIN_DECLS

#define GLS_TYPE_DUMMY            (gls_dummy_get_type())
#define GLS_DUMMY(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GLS_TYPE_DUMMY, GlsDummy))
#define GLS_DUMMY_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GLS_TYPE_DUMMY, GlsDummyClass))
#define GLS_IS_DUMMY(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GLS_TYPE_DUMMY))
#define GLS_IS_DUMMY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GLS_TYPE_DUMMY))
#define GLS_DUMMY_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GLS_TYPE_DUMMY, GlsDummyClass))

typedef struct _GlsDummy GlsDummy;
typedef struct _GlsDummyClass GlsDummyClass;

struct _GlsDummy {
	/*< private >*/
	GObject parent_instance;

	/*< public >*/
	gint id;
};

struct _GlsDummyClass {
	/*< private >*/
	GObjectClass parent_class;
};

GType     gls_dummy_get_type();
GlsDummy *gls_dummy_new();
guint     gls_dummy_hash(gconstpointer key);

G_END_DECLS

#endif /* __GLS_DUMMY_H__ */

