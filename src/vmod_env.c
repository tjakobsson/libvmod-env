#include <stdlib.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"

#include "vcc_if.h"

int
init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	return (0);
}

const char * 
vmod_get(struct sess *sp, const char *name) 
{ 
	return getenv(name); 
}
