/* note.c generated by valac 0.48.6, the Vala compiler
 * generated from note.vala, do not modify */

/*
 *  Notes - panel plugin for Xfce Desktop Environment
 *  Copyright (c) 2009-2010  Mike Massonnet <mmassonnet@xfce.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <gtk/gtk.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

#define XNP_TYPE_NOTE (xnp_note_get_type ())
#define XNP_NOTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNP_TYPE_NOTE, XnpNote))
#define XNP_NOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNP_TYPE_NOTE, XnpNoteClass))
#define XNP_IS_NOTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNP_TYPE_NOTE))
#define XNP_IS_NOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNP_TYPE_NOTE))
#define XNP_NOTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNP_TYPE_NOTE, XnpNoteClass))

typedef struct _XnpNote XnpNote;
typedef struct _XnpNoteClass XnpNoteClass;
typedef struct _XnpNotePrivate XnpNotePrivate;

#define XNP_TYPE_HYPERTEXT_VIEW (xnp_hypertext_view_get_type ())
#define XNP_HYPERTEXT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), XNP_TYPE_HYPERTEXT_VIEW, XnpHypertextView))
#define XNP_HYPERTEXT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), XNP_TYPE_HYPERTEXT_VIEW, XnpHypertextViewClass))
#define XNP_IS_HYPERTEXT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XNP_TYPE_HYPERTEXT_VIEW))
#define XNP_IS_HYPERTEXT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XNP_TYPE_HYPERTEXT_VIEW))
#define XNP_HYPERTEXT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), XNP_TYPE_HYPERTEXT_VIEW, XnpHypertextViewClass))

typedef struct _XnpHypertextView XnpHypertextView;
typedef struct _XnpHypertextViewClass XnpHypertextViewClass;
enum  {
	XNP_NOTE_0_PROPERTY,
	XNP_NOTE_NAME_PROPERTY,
	XNP_NOTE_DIRTY_PROPERTY,
	XNP_NOTE_NUM_PROPERTIES
};
static GParamSpec* xnp_note_properties[XNP_NOTE_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
enum  {
	XNP_NOTE_SAVE_DATA_SIGNAL,
	XNP_NOTE_NUM_SIGNALS
};
static guint xnp_note_signals[XNP_NOTE_NUM_SIGNALS] = {0};

struct _XnpNote {
	GtkScrolledWindow parent_instance;
	XnpNotePrivate * priv;
	XnpHypertextView* text_view;
};

struct _XnpNoteClass {
	GtkScrolledWindowClass parent_class;
};

struct _XnpNotePrivate {
	gchar* _name;
	guint save_timeout;
	gboolean _dirty;
};

static gint XnpNote_private_offset;
static gpointer xnp_note_parent_class = NULL;

GType xnp_note_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (XnpNote, g_object_unref)
GType xnp_hypertext_view_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (XnpHypertextView, g_object_unref)
void xnp_note_set_dirty (XnpNote* self,
                         gboolean value);
XnpNote* xnp_note_new (const gchar* name);
XnpNote* xnp_note_construct (GType object_type,
                             const gchar* name);
void xnp_note_set_name (XnpNote* self,
                        const gchar* value);
XnpHypertextView* xnp_hypertext_view_new (void);
XnpHypertextView* xnp_hypertext_view_construct (GType object_type);
static void xnp_note_buffer_changed_cb (XnpNote* self);
static void _xnp_note_buffer_changed_cb_gtk_text_buffer_changed (GtkTextBuffer* _sender,
                                                          gpointer self);
static gboolean xnp_note_save_cb (XnpNote* self);
const gchar* xnp_note_get_name (XnpNote* self);
gboolean xnp_note_get_dirty (XnpNote* self);
static gboolean _xnp_note_save_cb_gsource_func (gpointer self);
static void xnp_note_finalize (GObject * obj);
static GType xnp_note_get_type_once (void);
static void _vala_xnp_note_get_property (GObject * object,
                                  guint property_id,
                                  GValue * value,
                                  GParamSpec * pspec);
static void _vala_xnp_note_set_property (GObject * object,
                                  guint property_id,
                                  const GValue * value,
                                  GParamSpec * pspec);

static inline gpointer
xnp_note_get_instance_private (XnpNote* self)
{
	return G_STRUCT_MEMBER_P (self, XnpNote_private_offset);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static void
_xnp_note_buffer_changed_cb_gtk_text_buffer_changed (GtkTextBuffer* _sender,
                                                     gpointer self)
{
	xnp_note_buffer_changed_cb ((XnpNote*) self);
}

XnpNote*
xnp_note_construct (GType object_type,
                    const gchar* name)
{
	XnpNote * self = NULL;
	XnpHypertextView* _tmp0_;
	XnpHypertextView* _tmp1_;
	XnpHypertextView* _tmp2_;
	XnpHypertextView* _tmp3_;
	XnpHypertextView* _tmp4_;
	XnpHypertextView* _tmp5_;
	XnpHypertextView* _tmp6_;
	XnpHypertextView* _tmp7_;
	GtkTextBuffer* buffer = NULL;
	XnpHypertextView* _tmp8_;
	GtkTextBuffer* _tmp9_;
	GtkTextBuffer* _tmp10_;
	g_return_val_if_fail (name != NULL, NULL);
	self = (XnpNote*) g_object_new (object_type, NULL);
	xnp_note_set_name (self, name);
	gtk_scrolled_window_set_policy ((GtkScrolledWindow*) self, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	_tmp0_ = xnp_hypertext_view_new ();
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->text_view);
	self->text_view = _tmp0_;
	_tmp1_ = self->text_view;
	gtk_widget_show ((GtkWidget*) _tmp1_);
	_tmp2_ = self->text_view;
	gtk_text_view_set_wrap_mode ((GtkTextView*) _tmp2_, GTK_WRAP_WORD);
	_tmp3_ = self->text_view;
	gtk_text_view_set_left_margin ((GtkTextView*) _tmp3_, 2);
	_tmp4_ = self->text_view;
	gtk_text_view_set_right_margin ((GtkTextView*) _tmp4_, 2);
	_tmp5_ = self->text_view;
	gtk_text_view_set_pixels_above_lines ((GtkTextView*) _tmp5_, 1);
	_tmp6_ = self->text_view;
	gtk_text_view_set_pixels_below_lines ((GtkTextView*) _tmp6_, 1);
	_tmp7_ = self->text_view;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp7_);
	_tmp8_ = self->text_view;
	_tmp9_ = gtk_text_view_get_buffer ((GtkTextView*) _tmp8_);
	_tmp10_ = _g_object_ref0 (_tmp9_);
	buffer = _tmp10_;
	g_signal_connect_object (buffer, "changed", (GCallback) _xnp_note_buffer_changed_cb_gtk_text_buffer_changed, self, 0);
	_g_object_unref0 (buffer);
	return self;
}

XnpNote*
xnp_note_new (const gchar* name)
{
	return xnp_note_construct (XNP_TYPE_NOTE, name);
}

/**
 * buffer_changed_cb:
 *
 * Reset the save_timeout as long as the buffer is under constant
 * changes and send the save-data signal.
 */
static void
xnp_note_buffer_changed_cb (XnpNote* self)
{
	g_return_if_fail (self != NULL);
	xnp_note_set_dirty (self, TRUE);
}

/**
 * save_cb:
 *
 * Send save-data signal.
 */
static gboolean
xnp_note_save_cb (XnpNote* self)
{
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_signal_emit (self, xnp_note_signals[XNP_NOTE_SAVE_DATA_SIGNAL], 0);
	self->priv->save_timeout = (guint) 0;
	self->priv->_dirty = FALSE;
	result = FALSE;
	return result;
}

const gchar*
xnp_note_get_name (XnpNote* self)
{
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_name;
	result = _tmp0_;
	return result;
}

void
xnp_note_set_name (XnpNote* self,
                   const gchar* value)
{
	g_return_if_fail (self != NULL);
	if (g_strcmp0 (value, xnp_note_get_name (self)) != 0) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup (value);
		_g_free0 (self->priv->_name);
		self->priv->_name = _tmp0_;
		g_object_notify_by_pspec ((GObject *) self, xnp_note_properties[XNP_NOTE_NAME_PROPERTY]);
	}
}

gboolean
xnp_note_get_dirty (XnpNote* self)
{
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_dirty;
	return result;
}

static gboolean
_xnp_note_save_cb_gsource_func (gpointer self)
{
	gboolean result;
	result = xnp_note_save_cb ((XnpNote*) self);
	return result;
}

void
xnp_note_set_dirty (XnpNote* self,
                    gboolean value)
{
	g_return_if_fail (self != NULL);
	self->priv->_dirty = value;
	if (self->priv->save_timeout > ((guint) 0)) {
		g_source_remove (self->priv->save_timeout);
	}
	if (value == FALSE) {
		self->priv->save_timeout = (guint) 0;
	} else {
		self->priv->save_timeout = g_timeout_add_seconds_full (G_PRIORITY_DEFAULT, (guint) 60, _xnp_note_save_cb_gsource_func, g_object_ref (self), g_object_unref);
	}
	g_object_notify_by_pspec ((GObject *) self, xnp_note_properties[XNP_NOTE_DIRTY_PROPERTY]);
}

static void
xnp_note_class_init (XnpNoteClass * klass,
                     gpointer klass_data)
{
	xnp_note_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &XnpNote_private_offset);
	G_OBJECT_CLASS (klass)->get_property = _vala_xnp_note_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_xnp_note_set_property;
	G_OBJECT_CLASS (klass)->finalize = xnp_note_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), XNP_NOTE_NAME_PROPERTY, xnp_note_properties[XNP_NOTE_NAME_PROPERTY] = g_param_spec_string ("name", "name", "name", NULL, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), XNP_NOTE_DIRTY_PROPERTY, xnp_note_properties[XNP_NOTE_DIRTY_PROPERTY] = g_param_spec_boolean ("dirty", "dirty", "dirty", FALSE, G_PARAM_STATIC_STRINGS | G_PARAM_READABLE | G_PARAM_WRITABLE));
	xnp_note_signals[XNP_NOTE_SAVE_DATA_SIGNAL] = g_signal_new ("save-data", XNP_TYPE_NOTE, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void
xnp_note_instance_init (XnpNote * self,
                        gpointer klass)
{
	self->priv = xnp_note_get_instance_private (self);
	self->priv->_dirty = FALSE;
}

static void
xnp_note_finalize (GObject * obj)
{
	XnpNote * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, XNP_TYPE_NOTE, XnpNote);
	xnp_note_set_dirty (self, FALSE);
	_g_object_unref0 (self->text_view);
	_g_free0 (self->priv->_name);
	G_OBJECT_CLASS (xnp_note_parent_class)->finalize (obj);
}

static GType
xnp_note_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (XnpNoteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) xnp_note_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (XnpNote), 0, (GInstanceInitFunc) xnp_note_instance_init, NULL };
	GType xnp_note_type_id;
	xnp_note_type_id = g_type_register_static (gtk_scrolled_window_get_type (), "XnpNote", &g_define_type_info, 0);
	XnpNote_private_offset = g_type_add_instance_private (xnp_note_type_id, sizeof (XnpNotePrivate));
	return xnp_note_type_id;
}

GType
xnp_note_get_type (void)
{
	static volatile gsize xnp_note_type_id__volatile = 0;
	if (g_once_init_enter (&xnp_note_type_id__volatile)) {
		GType xnp_note_type_id;
		xnp_note_type_id = xnp_note_get_type_once ();
		g_once_init_leave (&xnp_note_type_id__volatile, xnp_note_type_id);
	}
	return xnp_note_type_id__volatile;
}

static void
_vala_xnp_note_get_property (GObject * object,
                             guint property_id,
                             GValue * value,
                             GParamSpec * pspec)
{
	XnpNote * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, XNP_TYPE_NOTE, XnpNote);
	switch (property_id) {
		case XNP_NOTE_NAME_PROPERTY:
		g_value_set_string (value, xnp_note_get_name (self));
		break;
		case XNP_NOTE_DIRTY_PROPERTY:
		g_value_set_boolean (value, xnp_note_get_dirty (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}

static void
_vala_xnp_note_set_property (GObject * object,
                             guint property_id,
                             const GValue * value,
                             GParamSpec * pspec)
{
	XnpNote * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, XNP_TYPE_NOTE, XnpNote);
	switch (property_id) {
		case XNP_NOTE_NAME_PROPERTY:
		xnp_note_set_name (self, g_value_get_string (value));
		break;
		case XNP_NOTE_DIRTY_PROPERTY:
		xnp_note_set_dirty (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
