/* Copyright 2003, 20026 - Dirk-Willem van Gulik, All Rights Reserved

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#include <stdlib.h>
#include <stdio.h>

#include "../alphanumsort.h"

char *arr[] = { "aaa", "a", "aa", "foo3bar91p", "foo3bar91arse", "foo", "foo9", "foo32", "foo3", "foo12891", "baz", "foo12bar", "0010", "1", "109","11", "23", "9", "bar", "zz9", "foo1bar", "foo3bar91", "foo3bar9", "foo3bar2", "foo13","", "whb.button.macro-11", "whb.button.macro-12", "whb.button.macro-13", "whb.button.macro-1", "whb.button.macro-2", "whb.button.macro-3", "whb.button.macro-5", "whb.button.macro-6", "whb.button.macro-7", "whb.button.macro-8", "whb.button.macro-9", "whb.button.macro-10", "whb.button.macro-14", "whb.button.macro-4", "whb.button.macro-15", "whb.button.macro-16", "lcec.0.A.din-0-not", "lcec.0.A.din-1-not", "lcec.0.A.din-10-not", "lcec.0.A.din-11-not", "lcec.0.A.din-12-not", "lcec.0.A.din-13-not", "lcec.0.A.din-14-not", "lcec.0.A.din-15-not", "lcec.0.A.din-2-not", "lcec.0.A.din-3-not", "lcec.0.A.din-4-not", "lcec.0.A.din-5-not", "lcec.0.A.din-6-not", "lcec.0.A.din-7-not", "lcec.0.A.din-8-not", "lcec.0.A.din-9-not", "lcec.0.A.slave-online", "lcec.0.A.slave-oper", "lcec.0.A.slave-state-init", "lcec.0.A.slave-state-op", "lcec.0.A.slave-state-preop", "lcec.0.A.slave-state-safeop", "lcec.0.B.din-0-not", "lcec.0.B.din-1-not", "lcec.0.B.din-10-not", "lcec.0.B.din-11-not", "lcec.0.B.din-12-not", "lcec.0.B.din-13-not", "lcec.0.B.din-14-not", "lcec.0.B.din-15-not", "lcec.0.B.din-2-not", "lcec.0.B.din-3-not", "lcec.0.B.din-4-not", "lcec.0.B.din-5-not", "lcec.0.B.din-6-not", "lcec.0.B.din-7-not", "lcec.0.B.din-8-not", "lcec.0.B.din-9-not", "lcec.0.B.slave-online", "lcec.0.B.slave-oper", "lcec.0.B.slave-state-init", "lcec.0.B.slave-state-op", "lcec.0.B.slave-state-preop", "lcec.0.B.slave-state-safeop", "lcec.0.C.din-0-not", "lcec.0.C.din-1-not", "lcec.0.C.din-10-not", "lcec.0.C.din-11-not", "lcec.0.C.din-12-not", "lcec.0.C.din-13-not", "lcec.0.C.din-14-not", "lcec.0.C.din-15-not", "lcec.0.C.din-2-not", "lcec.0.C.din-3-not", "lcec.0.C.din-4-not", "lcec.0.C.din-5-not", "lcec.0.C.din-6-not", "lcec.0.C.din-7-not", "lcec.0.C.din-8-not", "lcec.0.C.din-9-not", "lcec.0.C.slave-online", "lcec.0.C.slave-oper", "lcec.0.C.slave-state-init", "lcec.0.C.slave-state-op", "lcec.0.C.slave-state-preop", "lcec.0.C.slave-state-safeop", "lcec.0.D1.slave-online", "lcec.0.D1.slave-oper", "lcec.0.D1.slave-state-init", "lcec.0.D1.slave-state-op", "lcec.0.D1.slave-state-preop", "lcec.0.D1.slave-state-safeop", "lcec.0.D2.ain-0-bias", "lcec.0.D2.ain-0-error", "lcec.0.D2.ain-0-overrange", "lcec.0.D2.ain-0-raw", "lcec.0.D2.ain-0-scale", "lcec.0.D2.ain-0-sync-err", "lcec.0.D2.ain-0-underrange", "lcec.0.D2.ain-0-val", "lcec.0.D2.ain-1-bias", "lcec.0.D2.ain-1-error", "lcec.0.D2.ain-1-overrange", "lcec.0.D2.ain-1-raw", "lcec.0.D2.ain-1-scale", "lcec.0.D2.ain-1-sync-err", "lcec.0.D2.ain-1-underrange", "lcec.0.D2.ain-1-val", "lcec.0.D2.ain-2-bias", "lcec.0.D2.ain-2-error", "lcec.0.D2.ain-2-overrange", "lcec.0.D2.ain-2-raw", "lcec.0.D2.ain-2-scale", "lcec.0.D2.ain-2-sync-err", "lcec.0.D2.ain-2-underrange", "lcec.0.D2.ain-2-val", "lcec.0.D2.ain-3-bias", "lcec.0.D2.ain-3-error", "lcec.0.D2.ain-3-overrange", "lcec.0.D2.ain-3-raw", "lcec.0.D2.ain-3-scale", "lcec.0.D2.ain-3-sync-err", "lcec.0.D2.ain-3-underrange", "lcec.0.D2.ain-3-val", "lcec.0.D2.slave-online", "lcec.0.D2.slave-oper", "lcec.0.D2.slave-state-init", "lcec.0.D2.slave-state-op", "lcec.0.D2.slave-state-preop", "lcec.0.D2.slave-state-safeop", "lcec.0.P.slave-online", "lcec.0.P.slave-oper", "lcec.0.P.slave-state-init", "lcec.0.P.slave-state-op", "lcec.0.P.slave-state-preop", "lcec.0.P.slave-state-safeop", "lcec.0.Q.slave-online", "lcec.0.Q.slave-oper", "lcec.0.Q.slave-state-init", "lcec.0.Q.slave-state-op", "lcec.0.Q.slave-state-preop", "lcec.0.Q.slave-state-safeop", "lcec.0.all-op", "lcec.0.app-phase", "lcec.0.app-time-hi", "lcec.0.app-time-lo", "lcec.0.dc-phased", "lcec.0.dc-ref-err", "lcec.0.dc-sync-converged", "lcec.0.dc-sync-diff", "lcec.0.drift-mode", "lcec.0.link-up", "lcec.0.mono-time-hi", "lcec.0.mono-time-lo", "lcec.0.phase-jitter", "lcec.0.pll-drift", "lcec.0.pll-err", "lcec.0.pll-final", "lcec.0.pll-out", "lcec.0.pll-reset-count", "lcec.0.read.time", "lcec.0.slaves-responding", "lcec.0.state-init", "lcec.0.state-op", "lcec.0.state-preop", "lcec.0.state-safeop", "lcec.0.wkc", "lcec.0.wkc-change-count", "lcec.0.wkc-min", "lcec.0.wkc-reset", "lcec.0.wkc-state", "lcec.0.write.time", "lcec.all-op", "lcec.conf.master-count", "lcec.conf.slave-count", "lcec.link-up", "lcec.read-all.time", "lcec.slaves-responding", "lcec.state-init", "lcec.state-op", "lcec.state-preop", "lcec.state-safeop", "lcec.write-all.time", };

int main(int a, char **b) {
	size_t elems = sizeof(arr)/sizeof(*arr);

	qsort(arr,elems,sizeof(*arr),&alphanumsort);

	for(int i = 0; i < elems; i++)
		printf("%3d: >%s<\n",i+1,arr[i]);
	return 0;
}
