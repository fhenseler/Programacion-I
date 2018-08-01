#ifndef _GTKMM_OBJECT_P_H
#define _GTKMM_OBJECT_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class Object_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Object CppObjectType;
  typedef GObject BaseObjectType;
  typedef GObjectClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class Object;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);
};


} // namespace Gtk


#endif /* _GTKMM_OBJECT_P_H */
