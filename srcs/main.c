/*
    Made by ftsn.
    This file is part of ftsh.

    ftsh is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
    ftsh is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ftsh.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "tsh.h"

static void	init(char **env)
{
  app.env = new(_array, env, 0, 0);
}

static void	ending(void)
{
  delete(app.env);
}

int		main(int ac, char **av, char **env)
{
  char		*path_to_bin;

  init(env);
  path_to_bin = fetch_path("ls", "PATH", ":");
  printf("[%s]\n", path_to_bin);
  ending();
  (void)ac;
  (void)av;
  return (0);
}
