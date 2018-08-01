// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GIOMM_DBUSMETHODINVOCATION_H
#define _GIOMM_DBUSMETHODINVOCATION_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2010 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

//#include <giomm/dbusconnection.h>
#include <giomm/dbusmessage.h>
#include <giomm/dbusintrospection.h>
#include <glibmm/object.h>
#include <glibmm/variant.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusMethodInvocation = struct _GDBusMethodInvocation;
using GDBusMethodInvocationClass = struct _GDBusMethodInvocationClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{

namespace DBus
{ class MethodInvocation_Class; } // namespace DBus

} // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

class Error;

}

namespace Gio
{

namespace DBus
{

class Connection;


/** An Object for handling remote calls.
 * Instances of the MethodInvocation class are used when handling D-Bus
 * method calls. It provides a way to asynchronously return results and
 * errors.
 *
 * The normal way to obtain a MethodInvocation object is to receive it as
 * an argument to the SlotMethodCall that was passed to
 * Gio::DBus::Connection::register_object().
 *
 * @newin{2,28}
 * @ingroup DBus
 */

class MethodInvocation : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MethodInvocation;
  using CppClassType = MethodInvocation_Class;
  using BaseObjectType = GDBusMethodInvocation;
  using BaseClassType = GDBusMethodInvocationClass;

  // noncopyable
  MethodInvocation(const MethodInvocation&) = delete;
  MethodInvocation& operator=(const MethodInvocation&) = delete;

private:  friend class MethodInvocation_Class;
  static CppClassType methodinvocation_class_;

protected:
  explicit MethodInvocation(const Glib::ConstructParams& construct_params);
  explicit MethodInvocation(GDBusMethodInvocation* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MethodInvocation(MethodInvocation&& src) noexcept;
  MethodInvocation& operator=(MethodInvocation&& src) noexcept;

  ~MethodInvocation() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GDBusMethodInvocation*       gobj()       { return reinterpret_cast<GDBusMethodInvocation*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GDBusMethodInvocation* gobj() const { return reinterpret_cast<GDBusMethodInvocation*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GDBusMethodInvocation* gobj_copy();

private:


public:
  
  /** Gets the bus name that invoked the method.
   * 
   * @newin{2,26}
   * 
   * @return A string. Do not free, it is owned by @a invocation.
   */
  Glib::ustring get_sender() const;
  
  /** Gets the object path the method was invoked on.
   * 
   * @newin{2,26}
   * 
   * @return A string. Do not free, it is owned by @a invocation.
   */
  Glib::ustring get_object_path() const;
  
  /** Gets the name of the D-Bus interface the method was invoked on.
   * 
   * If this method call is a property Get, Set or GetAll call that has
   * been redirected to the method call handler then
   * "org.freedesktop.DBus.Properties" will be returned.  See
   * DBusInterfaceVTable for more information.
   * 
   * @newin{2,26}
   * 
   * @return A string. Do not free, it is owned by @a invocation.
   */
  Glib::ustring get_interface_name() const;
  
  /** Gets the name of the method that was invoked.
   * 
   * @newin{2,26}
   * 
   * @return A string. Do not free, it is owned by @a invocation.
   */
  Glib::ustring get_method_name() const;

 
  // The C API only returns a const GDBusMethodInfo.
  
  /** Gets information about the method call, if any.
   * 
   * If this method invocation is a property Get, Set or GetAll call that
   * has been redirected to the method call handler then <tt>nullptr</tt> will be
   * returned.  See g_dbus_method_invocation_get_property_info() and
   * DBusInterfaceVTable for more information.
   * 
   * @newin{2,26}
   * 
   * @return A DBusMethodInfo or <tt>nullptr</tt>. Do not free, it is owned by @a invocation.
   */
  Glib::RefPtr<const MethodInfo> get_method_info() const;

  
  /** Gets the DBusConnection the method was invoked on.
   * 
   * @newin{2,26}
   * 
   * @return A DBusConnection. Do not free, it is owned by @a invocation.
   */
  Glib::RefPtr<Connection> get_connection();
  
  /** Gets the DBusConnection the method was invoked on.
   * 
   * @newin{2,26}
   * 
   * @return A DBusConnection. Do not free, it is owned by @a invocation.
   */
  Glib::RefPtr<const Connection> get_connection() const;

  
  /** Gets the DBusMessage for the method invocation. This is useful if
   * you need to use low-level protocol features, such as UNIX file
   * descriptor passing, that cannot be properly expressed in the
   * Variant API.
   * 
   * See this [server][gdbus-server] and [client][gdbus-unix-fd-client]
   * for an example of how to use this low-level API to send and receive
   * UNIX file descriptors.
   * 
   * @newin{2,26}
   * 
   * @return DBusMessage. Do not free, it is owned by @a invocation.
   */
  Glib::RefPtr<Message> get_message();
  
  /** Gets the DBusMessage for the method invocation. This is useful if
   * you need to use low-level protocol features, such as UNIX file
   * descriptor passing, that cannot be properly expressed in the
   * Variant API.
   * 
   * See this [server][gdbus-server] and [client][gdbus-unix-fd-client]
   * for an example of how to use this low-level API to send and receive
   * UNIX file descriptors.
   * 
   * @newin{2,26}
   * 
   * @return DBusMessage. Do not free, it is owned by @a invocation.
   */
  Glib::RefPtr<const Message> get_message() const;

  //We assume that this is a tuple (VariantContainerBase).
  //See https://bugzilla.gnome.org/show_bug.cgi?id=646420
  
  /** Gets the parameters of the method invocation. If there are no input
   * parameters then this will return a GVariant with 0 children rather than <tt>nullptr</tt>.
   * 
   * @newin{2,26}
   * 
   * @return A Variant tuple. Do not unref this because it is owned by @a invocation.
   */
  Glib::VariantContainerBase get_parameters() const;

  //TODO: Add a return_single_value() method?
  //A return_value(VariantBase) would probably be ambiguous to people
  //even if it isn't ambiguous to the compiler.
  
  /** Finishes handling a D-Bus method call by returning @a parameters.
   * If the @a parameters GVariant is floating, it is consumed.
   * 
   * It is an error if @a parameters is not of the right format.
   * 
   * This method will free @a invocation, you cannot use it afterwards.
   * 
   * Since 2.48, if the method call requested for a reply not to be sent
   * then this call will sink @a parameters and free @a invocation, but
   * otherwise do nothing (as per the recommendations of the D-Bus
   * specification).
   * 
   * @newin{2,26}
   * 
   * @param parameters A Variant tuple with out parameters for the method or <tt>nullptr</tt> if not passing any parameters.
   */
  void return_value(const Glib::VariantContainerBase& parameters);

  
#ifdef  G_OS_UNIX

  /** Like g_dbus_method_invocation_return_value() but also takes a UnixFDList.
   * 
   * This method is only available on UNIX.
   * 
   * This method will free @a invocation, you cannot use it afterwards.
   * 
   * @newin{2,30}
   * 
   * @param parameters A Variant tuple with out parameters for the method or <tt>nullptr</tt> if not passing any parameters.
   * @param fd_list A UnixFDList or <tt>nullptr</tt>.
   */
  void return_value(const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list);
#endif //  G_OS_UNIX


  /** Like g_dbus_method_invocation_return_error() but without printf()-style formatting.
   * 
   * This method will free @a invocation, you cannot use it afterwards.
   * 
   * @newin{2,26}
   * 
   * @param domain A Quark for the Error error domain.
   * @param code The error code.
   * @param message The error message.
   */
  void return_error(const Glib::ustring& domain, int code, const Glib::ustring& message);

  // This function does not have to be wrapped because it's a convenience C
  // function to avoid having to unreference the error (in C).
  

  /** Like g_dbus_method_invocation_return_error() but takes a Error
   * instead of the error domain, error code and message.
   * 
   * This method will free @a invocation, you cannot use it afterwards.
   * 
   * @newin{2,26}
   */
  void return_error(const Glib::Error& error);

  
  /** Finishes handling a D-Bus method call by returning an error.
   * 
   * This method will free @a invocation, you cannot use it afterwards.
   * 
   * @newin{2,26}
   * 
   * @param error_name A valid D-Bus error name.
   * @param error_message A valid D-Bus error message.
   */
  void return_dbus_error(const Glib::ustring& error_name, const Glib::ustring& error_message);

  // Ignore vararg methods and ones that don't make sense for C++ API.
  

public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace DBus
} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DBus::MethodInvocation
   */
  Glib::RefPtr<Gio::DBus::MethodInvocation> wrap(GDBusMethodInvocation* object, bool take_copy = false);
}


#endif /* _GIOMM_DBUSMETHODINVOCATION_H */

