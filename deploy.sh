#!/bin/bash

version=$(git rev-list --no-merges --count HEAD)

cat > scripting/include/uac_version.inc <<EOT
#if defined _uac_version_included
	#endinput
#endif

#define _uac_version_included

#define UAC_MAJOR_VERSION       0
#define UAC_MINOR_VERSION       1
#define UAC_MAINTENANCE_VERSION $version
#define UAC_VERSION_STR         "0.1.$version-alpha"
EOT

zip -9 -r -q --exclude=".git/*" --exclude=".gitignore" --exclude=".gitkeep" --exclude=".travis.yml" --exclude="README.md" --exclude="deploy.sh" user-access-control.zip .
