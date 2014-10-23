============
vmod_env
============

----------------------
Varnish ENV Module
----------------------

:Author: Tobias Jakobsson
:Date: 2014-10-23
:Version: 0.1
:Manual section: 3

SYNOPSIS
========

import env;

DESCRIPTION
===========

Exposes ENV variables to Varnish VCL.


FUNCTIONS
=========

get
-----

Prototype
        ::

                get(STRING S)
Return value
	STRING
Description
	Returns ENV value (if any)
Example
        ::

                set resp.http.env = env.get("USER");

EXAMPLES
========
A practical example to use the same vcl code supporting production, staging or development environments.

        import env;

	backend default {
		.host = "127.0.0.1";
		.port = "8080";
	}

	backend production {
		.host = "192.168.0.10";
		.port = "8080";
	}
	
	backend staging {
		.host = "192.168.1.10";
		.port = "8080";
	}

        sub vcl_recv {
		if ( env.get( "ENVIRONMENT" ) == "production" ) {
			set req.backend = production;
		} else if ( env.get( "ENVIRONMENT ) == "staging" ) {
			set req.backend = staging;
		} else {
			set req.backend = default;
		}
        }

Running this command will use different backends:

ENVIRONMENT=production /etc/init.d/varnish start

ENVIRONMENT=staging /etc/init.d/varnish start

COPYRIGHT
=========

This document is licensed under the same license as the
libvmod-env project. See LICENSE for details.

* Copyright (c) 2014 Tobias Jakobsson 
