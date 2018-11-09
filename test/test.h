#ifndef TEST_H
#define TEST_H

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define MAXPATHLEN 512


/* Return the length of the text that can be considered the stem, returns 0
 * if there is no identifiable（可识别的） stem（词） */
static inline int get_stem_from_spec(const char *const buf)
{
    const char *tmp = strchr(buf + 1, '/');
    const char *ind;

    if (!tmp)
        return 0;

    for (ind = buf; ind < tmp; ind++) {
        if (strchr(".^$?*+|[({", (int)*ind))
            return 0;
    }
    return tmp - buf;
}





static int __dirname_r(const char* path, char* buffer, size_t buffer_size) {
  const char* endp = NULL;
  int len;
  int result;

  // Empty or NULL string gets treated as ".".
  if (path == NULL || *path == '\0') {
    path = ".";
    len = 1;
    goto Exit;
  }

  //    找path中最后一个非“/”字符位置
  // Strip trailing slashes.
  endp = path + strlen(path) - 1;
  while (endp > path && *endp == '/') {
    endp--;
  }

  //    找path中最后一个非“/”字符位置
  // Find the start of the dir.
  while (endp > path && *endp != '/') {
    endp--;
  }

  // Either the dir is "/" or there are no slashes.
  if (endp == path) {
    path = (*endp == '/') ? "/" : ".";
    len = 1;
    goto Exit;
  }

  do {
    endp--;
  } while (endp > path && *endp == '/');

  len = endp - path + 1;

 Exit:
  result = len;
  if (len + 1 > MAXPATHLEN) {
    errno = ENAMETOOLONG;
    return -1;
  }
  if (buffer == NULL) {
    return result;
  }

  if (len > static_cast<int>(buffer_size) - 1) {
    len = buffer_size - 1;
    result = -1;
    errno = ERANGE;
  }

  if (len >= 0) {
    memcpy(buffer, path, len);
    buffer[len] = 0;
  }
  return result;
}


static int __basename_r(const char* path, char* buffer, size_t buffer_size) {
  const char* startp = NULL;
  const char* endp = NULL;
  int len;
  int result;

  // Empty or NULL string gets treated as ".".
  if (path == NULL || *path == '\0') {
    startp = ".";
    len = 1;
    goto Exit;
  }

  // Strip trailing slashes.
  endp = path + strlen(path) - 1;
  while (endp > path && *endp == '/') {
    endp--;
  }

  // All slashes becomes "/".
  if (endp == path && *endp == '/') {
    startp = "/";
    len = 1;
    goto Exit;
  }

  // Find the start of the base.
  startp = endp;
  while (startp > path && *(startp - 1) != '/') {
    startp--;
  }

  len = endp - startp +1;

 Exit:
  result = len;
  if (buffer == NULL) {
    return result;
  }
  if (len > static_cast<int>(buffer_size) - 1) {
    len = buffer_size - 1;
    result = -1;
    errno = ERANGE;
  }

  if (len >= 0) {
    memcpy(buffer, startp, len);
    buffer[len] = 0;
  }
  return result;
}




#endif // TEST_H
