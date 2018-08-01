// Generated by gmmproc 2.50.0 -- DO NOT MODIFY!
#ifndef _GIOMM_TLSCONNECTION_H
#define _GIOMM_TLSCONNECTION_H

#include <giommconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2013 The giomm Development Team
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


#include <giomm/iostream.h>
#include <giomm/tlscertificate.h>
#include <giomm/asyncresult.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GTlsConnection = struct _GTlsConnection;
using GTlsConnectionClass = struct _GTlsConnectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class TlsConnection_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var TlsRehandshakeMode TLS_REHANDSHAKE_NEVER
 * Never allow rehandshaking.
 * 
 *  @var TlsRehandshakeMode TLS_REHANDSHAKE_SAFELY
 * Allow safe rehandshaking only.
 * 
 *  @var TlsRehandshakeMode TLS_REHANDSHAKE_UNSAFELY
 * Allow unsafe rehandshaking.
 * 
 *  @enum TlsRehandshakeMode
 * 
 * When to allow rehandshaking. See
 * g_tls_connection_set_rehandshake_mode().
 * 
 * @newin{2,28}
 *
 * @ingroup giommEnums
 */
enum TlsRehandshakeMode
{
  TLS_REHANDSHAKE_NEVER,
  TLS_REHANDSHAKE_SAFELY,
  TLS_REHANDSHAKE_UNSAFELY
};

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gio::TlsRehandshakeMode> : public Glib::Value_Enum<Gio::TlsRehandshakeMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


class Cancellable;
class TlsDatabase;
class TlsInteraction;

/** TlsConnection - TLS connection type.
 * TlsConnection is the base TLS connection class type, which wraps an IOStream
 * and provides TLS encryption on top of it. Its subclasses,
 * TlsClientConnection and TlsServerConnection, implement client-side and
 * server-side TLS, respectively.
 * @newin{2,36}
 */

class TlsConnection : public IOStream
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = TlsConnection;
  using CppClassType = TlsConnection_Class;
  using BaseObjectType = GTlsConnection;
  using BaseClassType = GTlsConnectionClass;

  // noncopyable
  TlsConnection(const TlsConnection&) = delete;
  TlsConnection& operator=(const TlsConnection&) = delete;

private:  friend class TlsConnection_Class;
  static CppClassType tlsconnection_class_;

protected:
  explicit TlsConnection(const Glib::ConstructParams& construct_params);
  explicit TlsConnection(GTlsConnection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  TlsConnection(TlsConnection&& src) noexcept;
  TlsConnection& operator=(TlsConnection&& src) noexcept;

  ~TlsConnection() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GTlsConnection*       gobj()       { return reinterpret_cast<GTlsConnection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GTlsConnection* gobj() const { return reinterpret_cast<GTlsConnection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GTlsConnection* gobj_copy();

private:


protected:
  TlsConnection();

public:
  
  /** This sets the certificate that @a conn will present to its peer
   * during the TLS handshake. For a TlsServerConnection, it is
   * mandatory to set this, and that will normally be done at construct
   * time.
   * 
   * For a TlsClientConnection, this is optional. If a handshake fails
   * with TLS_ERROR_CERTIFICATE_REQUIRED, that means that the server
   * requires a certificate, and if you try connecting again, you should
   * call this method first. You can call
   * g_tls_client_connection_get_accepted_cas() on the failed connection
   * to get a list of Certificate Authorities that the server will
   * accept certificates from.
   * 
   * (It is also possible that a server will allow the connection with
   * or without a certificate; in that case, if you don't provide a
   * certificate, you can tell that the server requested one by the fact
   * that g_tls_client_connection_get_accepted_cas() will return
   * non-<tt>nullptr</tt>.)
   * 
   * @newin{2,28}
   * 
   * @param certificate The certificate to use for @a conn.
   */
  void set_certificate(const Glib::RefPtr<TlsCertificate>& certificate);

  
  /** Gets @a conn's certificate, as set by
   * g_tls_connection_set_certificate().
   * 
   * @newin{2,28}
   * 
   * @return  @a conn's certificate, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<TlsCertificate> get_certificate();
  
  /** Gets @a conn's certificate, as set by
   * g_tls_connection_set_certificate().
   * 
   * @newin{2,28}
   * 
   * @return  @a conn's certificate, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<const TlsCertificate> get_certificate() const;

  
  /** Gets @a conn's peer's certificate after the handshake has completed.
   * (It is not set during the emission of
   * TlsConnection::signal_accept_certificate().)
   * 
   * @newin{2,28}
   * 
   * @return  @a conn's peer's certificate, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<TlsCertificate> get_peer_certificate();
  
  /** Gets @a conn's peer's certificate after the handshake has completed.
   * (It is not set during the emission of
   * TlsConnection::signal_accept_certificate().)
   * 
   * @newin{2,28}
   * 
   * @return  @a conn's peer's certificate, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<const TlsCertificate> get_peer_certificate() const;

  
  /** Gets the errors associated with validating @a conn's peer's
   * certificate, after the handshake has completed. (It is not set
   * during the emission of TlsConnection::signal_accept_certificate().)
   * 
   * @newin{2,28}
   * 
   * @return  @a conn's peer's certificate errors.
   */
  TlsCertificateFlags get_peer_certificate_errors() const;

  
  /** Sets whether or not @a conn expects a proper TLS close notification
   * before the connection is closed. If this is <tt>true</tt> (the default),
   * then @a conn will expect to receive a TLS close notification from its
   * peer before the connection is closed, and will return a
   * TLS_ERROR_EOF error if the connection is closed without proper
   * notification (since this may indicate a network error, or
   * man-in-the-middle attack).
   * 
   * In some protocols, the application will know whether or not the
   * connection was closed cleanly based on application-level data
   * (because the application-level data includes a length field, or is
   * somehow self-delimiting); in this case, the close notify is
   * redundant and sometimes omitted. (TLS 1.1 explicitly allows this;
   * in TLS 1.0 it is technically an error, but often done anyway.) You
   * can use g_tls_connection_set_require_close_notify() to tell @a conn
   * to allow an "unannounced" connection close, in which case the close
   * will show up as a 0-length read, as in a non-TLS
   * SocketConnection, and it is up to the application to check that
   * the data has been fully received.
   * 
   * Note that this only affects the behavior when the peer closes the
   * connection; when the application calls g_io_stream_close() itself
   * on @a conn, this will send a close notification regardless of the
   * setting of this property. If you explicitly want to do an unclean
   * close, you can close @a conn's TlsConnection::property_base_io_stream() rather
   * than closing @a conn itself, but note that this may only be done when no other
   * operations are pending on @a conn or the base I/O stream.
   * 
   * @newin{2,28}
   * 
   * @param require_close_notify Whether or not to require close notification.
   */
  void set_require_close_notify(bool require_close_notify =  true);
  
  /** Tests whether or not @a conn expects a proper TLS close notification
   * when the connection is closed. See
   * g_tls_connection_set_require_close_notify() for details.
   * 
   * @newin{2,28}
   * 
   * @return <tt>true</tt> if @a conn requires a proper TLS close
   * notification.
   */
  bool get_require_close_notify() const;

  
  /** Sets how @a conn behaves with respect to rehandshaking requests.
   * 
   * TLS_REHANDSHAKE_NEVER means that it will never agree to
   * rehandshake after the initial handshake is complete. (For a client,
   * this means it will refuse rehandshake requests from the server, and
   * for a server, this means it will close the connection with an error
   * if the client attempts to rehandshake.)
   * 
   * TLS_REHANDSHAKE_SAFELY means that the connection will allow a
   * rehandshake only if the other end of the connection supports the
   * TLS `renegotiation_info` extension. This is the default behavior,
   * but means that rehandshaking will not work against older
   * implementations that do not support that extension.
   * 
   * TLS_REHANDSHAKE_UNSAFELY means that the connection will allow
   * rehandshaking even without the `renegotiation_info` extension. On
   * the server side in particular, this is not recommended, since it
   * leaves the server open to certain attacks. However, this mode is
   * necessary if you need to allow renegotiation with older client
   * software.
   * 
   * @newin{2,28}
   * 
   * @param mode The rehandshaking mode.
   */
  void set_rehandshake_mode(TlsRehandshakeMode mode);
  
  /** Gets @a conn rehandshaking mode. See
   * g_tls_connection_set_rehandshake_mode() for details.
   * 
   * @newin{2,28}
   * 
   * @return  @a conn's rehandshaking mode.
   */
  TlsRehandshakeMode get_rehandshake_mode() const;

  
#ifndef GIOMM_DISABLE_DEPRECATED

  /** Sets whether @a conn uses the system certificate database to verify
   * peer certificates. This is <tt>true</tt> by default. If set to <tt>false</tt>, then
   * peer certificate validation will always set the
   * TLS_CERTIFICATE_UNKNOWN_CA error (meaning
   * TlsConnection::signal_accept_certificate() will always be emitted on
   * client-side connections, unless that bit is not set in
   * TlsClientConnection::property_validation_flags()).
   * 
   * Deprecated: 2.30: Use g_tls_connection_set_database() instead
   * 
   * @deprecated Use set_database() instead.
   * 
   * @param use_system_certdb Whether to use the system certificate database.
   */
  void set_use_system_certdb(bool use_system_certdb =  true);
#endif // GIOMM_DISABLE_DEPRECATED


#ifndef GIOMM_DISABLE_DEPRECATED

  /** Gets whether @a conn uses the system certificate database to verify
   * peer certificates. See g_tls_connection_set_use_system_certdb().
   * 
   * Deprecated: 2.30: Use g_tls_connection_get_database() instead
   * 
   * @deprecated Use get_database() instead.
   * 
   * @return Whether @a conn uses the system certificate database.
   */
  bool get_use_system_certdb() const;
#endif // GIOMM_DISABLE_DEPRECATED


  /** Gets the certificate database that @a conn uses to verify
   * peer certificates. See g_tls_connection_set_database().
   * 
   * @newin{2,30}
   * 
   * @return The certificate database that @a conn uses or <tt>nullptr</tt>.
   */
  Glib::RefPtr<TlsDatabase> get_database();
  
  /** Gets the certificate database that @a conn uses to verify
   * peer certificates. See g_tls_connection_set_database().
   * 
   * @newin{2,30}
   * 
   * @return The certificate database that @a conn uses or <tt>nullptr</tt>.
   */
  Glib::RefPtr<const TlsDatabase> get_database() const;

  
  /** Sets the certificate database that is used to verify peer certificates.
   * This is set to the default database by default. See
   * g_tls_backend_get_default_database(). If set to <tt>nullptr</tt>, then
   * peer certificate validation will always set the
   * TLS_CERTIFICATE_UNKNOWN_CA error (meaning
   * TlsConnection::signal_accept_certificate() will always be emitted on
   * client-side connections, unless that bit is not set in
   * TlsClientConnection::property_validation_flags()).
   * 
   * @newin{2,30}
   * 
   * @param database A TlsDatabase.
   */
  void set_database(const Glib::RefPtr<TlsDatabase>& database);

  
  /** Get the object that will be used to interact with the user. It will be used
   * for things like prompting the user for passwords. If <tt>nullptr</tt> is returned, then
   * no user interaction will occur for this connection.
   * 
   * @newin{2,30}
   * 
   * @return The interaction object.
   */
  Glib::RefPtr<TlsInteraction> get_interaction();
  
  /** Get the object that will be used to interact with the user. It will be used
   * for things like prompting the user for passwords. If <tt>nullptr</tt> is returned, then
   * no user interaction will occur for this connection.
   * 
   * @newin{2,30}
   * 
   * @return The interaction object.
   */
  Glib::RefPtr<const TlsInteraction> get_interaction() const;

  
  /** Set the object that will be used to interact with the user. It will be used
   * for things like prompting the user for passwords.
   * 
   * The @a interaction argument will normally be a derived subclass of
   * TlsInteraction. <tt>nullptr</tt> can also be provided if no user interaction
   * should occur for this connection.
   * 
   * @newin{2,30}
   * 
   * @param interaction An interaction object, or <tt>nullptr</tt>.
   */
  void set_interaction(const Glib::RefPtr<TlsInteraction>& interaction);

  
  /** Attempts a TLS handshake on @a conn.
   * 
   * On the client side, it is never necessary to call this method;
   * although the connection needs to perform a handshake after
   * connecting (or after sending a "STARTTLS"-type command) and may
   * need to rehandshake later if the server requests it,
   * TlsConnection will handle this for you automatically when you try
   * to send or receive data on the connection. However, you can call
   * g_tls_connection_handshake() manually if you want to know for sure
   * whether the initial handshake succeeded or failed (as opposed to
   * just immediately trying to write to @a conn's output stream, in which
   * case if it fails, it may not be possible to tell if it failed
   * before or after completing the handshake).
   * 
   * Likewise, on the server side, although a handshake is necessary at
   * the beginning of the communication, you do not need to call this
   * function explicitly unless you want clearer error reporting.
   * However, you may call g_tls_connection_handshake() later on to
   * renegotiate parameters (encryption methods, etc) with the client.
   * 
   * TlsConnection::accept_certificate may be emitted during the
   * handshake.
   * 
   * @newin{2,28}
   * 
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return Success or failure.
   */
  bool handshake(const Glib::RefPtr<Cancellable>& cancellable);

  /// A handshake() convenience overload.
  bool handshake();

  
  /** Asynchronously performs a TLS handshake on @a conn. See
   * g_tls_connection_handshake() for more information.
   * 
   * @newin{2,28}
   * 
   * @param io_priority The [I/O priority][io-priority] of the request.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot Callback to call when the handshake is complete.
   */
  void handshake_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority =  Glib::PRIORITY_DEFAULT);

  /// A handshake_async() convenience overload.
  void handshake_async(const SlotAsyncReady& slot, int io_priority =  Glib::PRIORITY_DEFAULT);
  
  /** Finish an asynchronous TLS handshake operation. See
   * g_tls_connection_handshake() for more information.
   * 
   * @newin{2,28}
   * 
   * @param result A AsyncResult.
   * @return <tt>true</tt> on success, <tt>false</tt> on failure, in which
   * case @a error will be set.
   */
  bool handshake_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /** Used by TlsConnection implementations to emit the
   * TlsConnection::signal_accept_certificate() signal.
   * 
   * @newin{2,28}
   * 
   * @param peer_cert The peer's TlsCertificate.
   * @param errors The problems with @a peer_cert.
   * @return <tt>true</tt> if one of the signal handlers has returned
   * <tt>true</tt> to accept @a peer_cert.
   */
  bool emit_accept_certificate(const Glib::RefPtr<const TlsCertificate>& peer_cert, TlsCertificateFlags errors);

  /** The IOStream that the connection wraps. The connection holds a reference
   * to this stream, and may run operations on the stream from other threads
   * throughout its lifetime. Consequently, after the IOStream has been
   * constructed, application code may only run its own operations on this
   * stream when no IOStream operations are running.
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<IOStream> > property_base_io_stream() const;


  /** The connection's certificate; see
   * g_tls_connection_set_certificate().
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<TlsCertificate> > property_certificate() ;

/** The connection's certificate; see
   * g_tls_connection_set_certificate().
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsCertificate> > property_certificate() const;

  /** The certificate database to use when verifying this TLS connection.
   * If no certificate database is set, then the default database will be
   * used. See g_tls_backend_get_default_database().
   * 
   * @newin{2,30}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<TlsDatabase> > property_database() ;

/** The certificate database to use when verifying this TLS connection.
   * If no certificate database is set, then the default database will be
   * used. See g_tls_backend_get_default_database().
   * 
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsDatabase> > property_database() const;

  /** A TlsInteraction object to be used when the connection or certificate
   * database need to interact with the user. This will be used to prompt the
   * user for passwords where necessary.
   * 
   * @newin{2,30}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<TlsInteraction> > property_interaction() ;

/** A TlsInteraction object to be used when the connection or certificate
   * database need to interact with the user. This will be used to prompt the
   * user for passwords where necessary.
   * 
   * @newin{2,30}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsInteraction> > property_interaction() const;

  /** The connection's peer's certificate, after the TLS handshake has
   * completed and the certificate has been accepted. Note in
   * particular that this is not yet set during the emission of
   * TlsConnection::signal_accept_certificate().
   * 
   * (You can watch for a Object::signal_notify() signal on this property to
   * detect when a handshake has occurred.)
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TlsCertificate> > property_peer_certificate() const;


  /** The errors noticed-and-ignored while verifying
   * TlsConnection::property_peer_certificate(). Normally this should be 0, but
   * it may not be if TlsClientConnection::property_validation_flags() is not
   * TLS_CERTIFICATE_VALIDATE_ALL, or if
   * TlsConnection::signal_accept_certificate() overrode the default
   * behavior.
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< TlsCertificateFlags > property_peer_certificate_errors() const;


  /** The rehandshaking mode. See
   * g_tls_connection_set_rehandshake_mode().
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< TlsRehandshakeMode > property_rehandshake_mode() ;

/** The rehandshaking mode. See
   * g_tls_connection_set_rehandshake_mode().
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< TlsRehandshakeMode > property_rehandshake_mode() const;

  /** Whether or not proper TLS close notification is required.
   * See g_tls_connection_set_require_close_notify().
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_require_close_notify() ;

/** Whether or not proper TLS close notification is required.
   * See g_tls_connection_set_require_close_notify().
   * 
   * @newin{2,28}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_require_close_notify() const;

  
#ifndef GIOMM_DISABLE_DEPRECATED

/** Whether or not the system certificate database will be used to
   * verify peer certificates. See
   * g_tls_connection_set_use_system_certdb().
   * 
   * Deprecated: 2.30: Use GTlsConnection:database instead
   * 
   * @deprecated Use property_database() instead.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_system_certdb() ;

/** Whether or not the system certificate database will be used to
   * verify peer certificates. See
   * g_tls_connection_set_use_system_certdb().
   * 
   * Deprecated: 2.30: Use GTlsConnection:database instead
   * 
   * @deprecated Use property_database() instead.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_system_certdb() const;

#endif // GIOMM_DISABLE_DEPRECATED


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%accept_certificate(const Glib::RefPtr<const TlsCertificate>& peer_cert, TlsCertificateFlags errors)</tt>
   *
   * Emitted during the TLS handshake after the peer certificate has
   * been received. You can examine @a peer_cert's certification path by
   * calling g_tls_certificate_get_issuer() on it.
   * 
   * For a client-side connection, @a peer_cert is the server's
   * certificate, and the signal will only be emitted if the
   * certificate was not acceptable according to @a conn's
   * TlsClientConnection::property_validation()_flags. If you would like the
   * certificate to be accepted despite @a errors, return <tt>true</tt> from the
   * signal handler. Otherwise, if no handler accepts the certificate,
   * the handshake will fail with TLS_ERROR_BAD_CERTIFICATE.
   * 
   * For a server-side connection, @a peer_cert is the certificate
   * presented by the client, if this was requested via the server's
   * TlsServerConnection::property_authentication()_mode. On the server side,
   * the signal is always emitted when the client presents a
   * certificate, and the certificate will only be accepted if a
   * handler returns <tt>true</tt>.
   * 
   * Note that if this signal is emitted as part of asynchronous I/O
   * in the main thread, then you should not attempt to interact with
   * the user before returning from the signal handler. If you want to
   * let the user decide whether or not to accept the certificate, you
   * would have to return <tt>false</tt> from the signal handler on the first
   * attempt, and then after the connection attempt returns a
   * TLS_ERROR_HANDSHAKE, you can interact with the user, and if
   * the user decides to accept the certificate, remember that fact,
   * create a new connection, and return <tt>true</tt> from the signal handler
   * the next time.
   * 
   * If you are doing I/O in another thread, you do not
   * need to worry about this, and can simply block in the signal
   * handler until the UI thread returns an answer.
   * 
   * @newin{2,28}
   * 
   * @param peer_cert The peer's TlsCertificate.
   * @param errors The problems with @a peer_cert.
   * @return <tt>true</tt> to accept @a peer_cert (which will also
   * immediately end the signal emission). <tt>false</tt> to allow the signal
   * emission to continue, which will cause the handshake to fail if
   * no one else overrides it.
   */

  Glib::SignalProxy< bool,const Glib::RefPtr<const TlsCertificate>&,TlsCertificateFlags > signal_accept_certificate();


  /// @throws Glib::Error.
  virtual bool handshake_vfunc(const Glib::RefPtr<Cancellable>& cancellable);

    virtual void handshake_async_vfunc(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority);


  /// @throws Glib::Error.
  virtual bool handshake_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_accept_certificate().
  virtual bool on_accept_certificate(const Glib::RefPtr<const TlsCertificate>& peer_cert, TlsCertificateFlags errors);


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
   * @relates Gio::TlsConnection
   */
  Glib::RefPtr<Gio::TlsConnection> wrap(GTlsConnection* object, bool take_copy = false);
}


#endif /* _GIOMM_TLSCONNECTION_H */

