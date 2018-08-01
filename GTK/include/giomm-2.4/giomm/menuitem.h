// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GIOMM_MENUITEM_H
#define _GIOMM_MENUITEM_H

#include <giommconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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


#include <glibmm/object.h>
#include <giomm/menumodel.h>
#include <giomm/icon.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenuItem = struct _GMenuItem;
using GMenuItemClass = struct _GMenuItemClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class MenuItem_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A menu item for use with Gio::Menu.
 *
 * @newin{2,32}
 */

class MenuItem : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MenuItem;
  using CppClassType = MenuItem_Class;
  using BaseObjectType = GMenuItem;
  using BaseClassType = GMenuItemClass;

  // noncopyable
  MenuItem(const MenuItem&) = delete;
  MenuItem& operator=(const MenuItem&) = delete;

private:  friend class MenuItem_Class;
  static CppClassType menuitem_class_;

protected:
  explicit MenuItem(const Glib::ConstructParams& construct_params);
  explicit MenuItem(GMenuItem* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MenuItem(MenuItem&& src) noexcept;
  MenuItem& operator=(MenuItem&& src) noexcept;

  ~MenuItem() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GMenuItem*       gobj()       { return reinterpret_cast<GMenuItem*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GMenuItem* gobj() const { return reinterpret_cast<GMenuItem*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GMenuItem* gobj_copy();

private:


protected:
  /** Creates a new MenuItem.
   *
   * If @a label is not empty it is used to set the "label" attribute of the
   * new item.
   *
   * If @a detailed_action is not empty it is used to set the "action" and
   * possibly the "target" attribute of the new item.  See
   * set_detailed_action() for more information.
   *
   * @param label The section label.
   * @param detailed_action: The detailed action string.
   */
  explicit MenuItem(const Glib::ustring& label = Glib::ustring(), const Glib::ustring& detailed_action = Glib::ustring());
  

  /** Creates a new MenuItem representing a submenu.
   *
   * This is a convenience API around the MenuItem(label, detailed_action) constructor and
   * set_submenu().
   *
   * @param label The section label.
   * @param submenu A MenuModel with the items of the submenu.
   */
  explicit MenuItem(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu);

  /** Creates a new MenuItem representing a submenu.
   *
   * This is a convenience API around the MenuItem(label, detailed_action) constructor and
   * set_submenu().
   *
   * @param submenu A MenuModel with the items of the submenu.
   */
  explicit MenuItem(const Glib::RefPtr<MenuModel>& submenu);
  

public:
  
  static Glib::RefPtr<MenuItem> create(const Glib::ustring& label, const Glib::ustring& detailed_action);


  static Glib::RefPtr<MenuItem> create(const Glib::ustring& label, const Glib::RefPtr<MenuModel>& submenu);

  /// A create() convenience overload.
  static Glib::RefPtr<MenuItem> create(const Glib::RefPtr<MenuModel>& submenu);


/* TODO:
GMenuItem * g_menu_item_new_from_model              (GMenuModel  *model,
                                                     gint         item_index);


GMenuItem * g_menu_item_new_submenu                 (const Glib::ustring& label,
                                                     GMenuModel  *submenu);


GMenuItem * g_menu_item_new_section                 (const Glib::ustring& label,
                                                     GMenuModel  *section);
*/


//TODO: GMenuItem * g_menu_item_new_section                 (const Glib::ustring& label,
//                                                     const Glib::RefPtr<MenuModel>& section);

  //TODO: Add a set_attribute() templated method to get values directly instead
  //of requiring a Glib::VariantBase, when we can break ABI:
  //template <typename T_Value>
  //void set_attribute(const Glib::ustring& attribute, const T_Value& value) const;

  
  /** Sets or unsets an attribute on @a menu_item.
   * 
   * The attribute to set or unset is specified by @a attribute. This
   * can be one of the standard attribute names MENU_ATTRIBUTE_LABEL,
   * MENU_ATTRIBUTE_ACTION, MENU_ATTRIBUTE_TARGET, or a custom
   * attribute name.
   * Attribute names are restricted to lowercase characters, numbers
   * and '-'. Furthermore, the names must begin with a lowercase character,
   * must not end with a '-', and must not contain consecutive dashes.
   * 
   * must consist only of lowercase
   * ASCII characters, digits and '-'.
   * 
   * If @a value is non-<tt>nullptr</tt> then it is used as the new value for the
   * attribute.  If @a value is <tt>nullptr</tt> then the attribute is unset. If
   * the @a value Variant is floating, it is consumed.
   * 
   * See also g_menu_item_set_attribute() for a more convenient way to do
   * the same.
   * 
   * @newin{2,32}
   * 
   * @param attribute The attribute to set.
   * @param value A Variant to use as the value, or <tt>nullptr</tt>.
   */
  void set_attribute_value(const Glib::ustring& attribute, const Glib::VariantBase& value);
  
#ifndef GIOMM_DISABLE_DEPRECATED

  /** Sets or unsets an attribute on @a menu_item.
   * 
   * The attribute to set or unset is specified by @a attribute. This
   * can be one of the standard attribute names MENU_ATTRIBUTE_LABEL,
   * MENU_ATTRIBUTE_ACTION, MENU_ATTRIBUTE_TARGET, or a custom
   * attribute name.
   * Attribute names are restricted to lowercase characters, numbers
   * and '-'. Furthermore, the names must begin with a lowercase character,
   * must not end with a '-', and must not contain consecutive dashes.
   * 
   * must consist only of lowercase
   * ASCII characters, digits and '-'.
   * 
   * If @a value is non-<tt>nullptr</tt> then it is used as the new value for the
   * attribute.  If @a value is <tt>nullptr</tt> then the attribute is unset. If
   * the @a value Variant is floating, it is consumed.
   * 
   * See also g_menu_item_set_attribute() for a more convenient way to do
   * the same.
   * 
   * @newin{2,32}
   * 
   * @deprecated Use set_attribute() instead.
   * 
   * @param attribute The attribute to set.
   * @param value A Variant to use as the value, or <tt>nullptr</tt>.
   */
  void set_attribute(const Glib::ustring& attribute, const Glib::VariantBase& value);
#endif // GIOMM_DISABLE_DEPRECATED


//These are documented as transfer-full, so we don't need to use refreturn.
  
  /** Queries the named @a link on @a menu_item.
   * 
   * @newin{2,34}
   * 
   * @param link The link name to query.
   * @return The link, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<MenuModel> get_link(const Glib::ustring& link);
  
  /** Queries the named @a link on @a menu_item.
   * 
   * @newin{2,34}
   * 
   * @param link The link name to query.
   * @return The link, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<const MenuModel> get_link(const Glib::ustring& link) const;

  
  /** Creates a link from @a menu_item to @a model if non-<tt>nullptr</tt>, or unsets it.
   * 
   * Links are used to establish a relationship between a particular menu
   * item and another menu.  For example, MENU_LINK_SUBMENU is used to
   * associate a submenu with a particular menu item, and MENU_LINK_SECTION
   * is used to create a section. Other types of link can be used, but there
   * is no guarantee that clients will be able to make sense of them.
   * Link types are restricted to lowercase characters, numbers
   * and '-'. Furthermore, the names must begin with a lowercase character,
   * must not end with a '-', and must not contain consecutive dashes.
   * 
   * @newin{2,32}
   * 
   * @param link Type of link to establish or unset.
   * @param model The MenuModel to link to (or <tt>nullptr</tt> to unset).
   */
  void set_link(const Glib::ustring& link, const Glib::RefPtr<MenuModel>& model);
  
  /** Sets or unsets the "label" attribute of @a menu_item.
   * 
   * If @a label is non-<tt>nullptr</tt> it is used as the label for the menu item.  If
   * it is <tt>nullptr</tt> then the label attribute is unset.
   * 
   * @newin{2,32}
   * 
   * @param label The label to set, or <tt>nullptr</tt> to unset.
   */
  void set_label(const Glib::ustring& label);
  
  /** Sets or unsets the "submenu" link of @a menu_item to @a submenu.
   * 
   * If @a submenu is non-<tt>nullptr</tt>, it is linked to.  If it is <tt>nullptr</tt> then the
   * link is unset.
   * 
   * The effect of having one menu appear as a submenu of another is
   * exactly as it sounds.
   * 
   * @newin{2,32}
   * 
   * @param submenu A MenuModel, or <tt>nullptr</tt>.
   */
  void set_submenu(const Glib::RefPtr<MenuModel>& submenu);
  
  /** Sets or unsets the "section" link of @a menu_item to @a section.
   * 
   * The effect of having one menu appear as a section of another is
   * exactly as it sounds: the items from @a section become a direct part of
   * the menu that @a menu_item is added to.  See g_menu_item_new_section()
   * for more information about what it means for a menu item to be a
   * section.
   * 
   * @newin{2,32}
   * 
   * @param section A MenuModel, or <tt>nullptr</tt>.
   */
  void set_section(const Glib::RefPtr<MenuModel>& section);

  //TODO: Add a get_attribute() templated method to get values directly instead
  //of returning a Glib::VariantBase, when we can break ABI.
  //template <typename T_Value>
  //void get_attribute(const Glib::ustring& attribute, T_Value& value) const;
  //_WRAP_METHOD(Glib::VariantBase get_attribute_value(const Glib::ustring& attribute, const Glib::VariantType& expected_type{?}) const, g_menu_item_get_attribute_value)

  
#ifndef GIOMM_DISABLE_DEPRECATED

  /** Queries the named @a attribute on @a menu_item.
   * 
   * If @a expected_type is specified and the attribute does not have this
   * type, <tt>nullptr</tt> is returned.  <tt>nullptr</tt> is also returned if the attribute
   * simply does not exist.
   * 
   * @newin{2,34}
   * 
   * @deprecated Use get_attribute_value() instead.
   * 
   * @param attribute The attribute name to query.
   * @param expected_type The expected type of the attribute.
   * @return The attribute value, or <tt>nullptr</tt>.
   */
  Glib::VariantBase get_attribute(const Glib::ustring& attribute, const Glib::VariantType& expected_type) const;
#endif // GIOMM_DISABLE_DEPRECATED


#ifndef GIOMM_DISABLE_DEPRECATED


  /// A get_attribute() convenience overload.
  Glib::VariantBase get_attribute(const Glib::ustring& attribute) const;
#endif // GIOMM_DISABLE_DEPRECATED


  /** Queries the named @a attribute on @a menu_item.
   * 
   * If @a expected_type is specified and the attribute does not have this
   * type, <tt>nullptr</tt> is returned.  <tt>nullptr</tt> is also returned if the attribute
   * simply does not exist.
   * 
   * @newin{2,34}
   * 
   * @param attribute The attribute name to query.
   * @param expected_type The expected type of the attribute.
   * @return The attribute value, or <tt>nullptr</tt>.
   */
  Glib::VariantBase get_attribute_value(const Glib::ustring& attribute, const Glib::VariantType& expected_type) const;

  /// A get_attribute_value() convenience overload.
  Glib::VariantBase get_attribute_value(const Glib::ustring& attribute) const;

  // Ignore varargs function.
  

#ifndef GIOMM_DISABLE_DEPRECATED

  /** Unsets the target for the specified @a action.
   * @deprecated Use set_action() or unset_target() instead.
   */
  void set_action_and_target(const Glib::ustring& action);
#endif // GIOMM_DISABLE_DEPRECATED


  /** Sets the action for the menu item.
   * See set_action_and_target().
   *
   * @newin{2,38}
   */
  void set_action(const Glib::ustring& action);

  /** Unsets the target for the menu item.
   * See set_action_and_target().
   *
   * @newin{2,38}
   */
  void unset_target();

  /** Unsets the action and target for the menu item.
   * See set_action_and_target().
   *
   * @newin{2,38}
   */
  void unset_action_and_target();

  
  /** Sets or unsets the "action" and "target" attributes of @a menu_item.
   * 
   * If @a action is <tt>nullptr</tt> then both the "action" and "target" attributes
   * are unset (and @a target_value is ignored).
   * 
   * If @a action is non-<tt>nullptr</tt> then the "action" attribute is set.  The
   * "target" attribute is then set to the value of @a target_value if it is
   * non-<tt>nullptr</tt> or unset otherwise.
   * 
   * Normal menu items (ie: not submenu, section or other custom item
   * types) are expected to have the "action" attribute set to identify
   * the action that they are associated with.  The state type of the
   * action help to determine the disposition of the menu item.  See
   * Action and ActionGroup for an overview of actions.
   * 
   * In general, clicking on the menu item will result in activation of
   * the named action with the "target" attribute given as the parameter
   * to the action invocation.  If the "target" attribute is not set then
   * the action is invoked with no parameter.
   * 
   * If the action has no state then the menu item is usually drawn as a
   * plain menu item (ie: with no additional decoration).
   * 
   * If the action has a boolean state then the menu item is usually drawn
   * as a toggle menu item (ie: with a checkmark or equivalent
   * indication).  The item should be marked as 'toggled' or 'checked'
   * when the boolean state is <tt>true</tt>.
   * 
   * If the action has a string state then the menu item is usually drawn
   * as a radio menu item (ie: with a radio bullet or equivalent
   * indication).  The item should be marked as 'selected' when the string
   * state is equal to the value of the @a target property.
   * 
   * See g_menu_item_set_action_and_target() or
   * g_menu_item_set_detailed_action() for two equivalent calls that are
   * probably more convenient for most uses.
   * 
   * @newin{2,32}
   * 
   * @param action The name of the action for this item.
   * @param target_value A Variant to use as the action target.
   */
  void set_action_and_target(const Glib::ustring& action, const Glib::VariantBase& target_value);
  
  
  /** Sets the "action" and possibly the "target" attribute of @a menu_item.
   * 
   * The format of @a detailed_action is the same format parsed by
   * g_action_parse_detailed_name().
   * 
   * See g_menu_item_set_action_and_target() or
   * g_menu_item_set_action_and_target_value() for more flexible (but
   * slightly less convenient) alternatives.
   * 
   * See also g_menu_item_set_action_and_target_value() for a description of
   * the semantics of the action and target attributes.
   * 
   * @newin{2,32}
   * 
   * @param detailed_action The "detailed" action string.
   */
  void set_detailed_action(const Glib::ustring& detailed_action);

 
  /** Sets (or unsets) the icon on @a menu_item.
   * 
   * This call is the same as calling g_icon_serialize() and using the
   * result as the value to g_menu_item_set_attribute_value() for
   * MENU_ATTRIBUTE_ICON.
   * 
   * This API is only intended for use with "noun" menu items; things like
   * bookmarks or applications in an "Open With" menu.  Don't use it on
   * menu items corresponding to verbs (eg: stock icons for 'Save' or
   * 'Quit').
   * 
   * If @a icon is <tt>nullptr</tt> then the icon is unset.
   * 
   * @newin{2,38}
   * 
   * @param icon A Icon, or <tt>nullptr</tt>.
   */
  void set_icon(const Glib::RefPtr<Icon>& icon);

  /** Unset the icon on the menu item.
   *
   * See set_icon().
   *
   * @newin{2,38}
   */
  void unset_icon();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::MenuItem
   */
  Glib::RefPtr<Gio::MenuItem> wrap(GMenuItem* object, bool take_copy = false);
}


#endif /* _GIOMM_MENUITEM_H */

