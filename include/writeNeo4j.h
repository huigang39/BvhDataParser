#ifndef _WRITENEO4J_H
#define _WRITENEO4J_H

#include <neo4j-client.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int addJoint(const char *jointName);
int addRelation(const char *fatherJoint, const char *childJoint);

#endif