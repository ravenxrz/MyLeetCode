import math


class Solution:
    def findClosest(self, words: list[str], word1: str, word2: str) -> int:
        min_dist = math.inf
        word1_idx = -1
        word2_idx = -1
        for i, word in enumerate(words):
            if word == word1:
                word1_idx = i
            elif word == word2:
                word2_idx = i
            if word1_idx != -1 and word2_idx != -1:
                min_dist = min(min_dist, abs(word2_idx - word1_idx))
        return min_dist


if __name__ == '__main__':
    words = ["ihe", "izx", "ypr", "uy", "ui", "kd", "sx", "ram", "t", "oix", "lau", "gp", "yqy", "wm", "le", "k", "v",
             "pa", "eie", "jck", "w", "b", "ox", "qwe", "qpm", "tqt", "hdc", "bep", "z", "y", "hqz", "fsc", "b", "cn",
             "e", "dzw", "ir", "pp", "imw", "njp", "vu", "gtf", "xog", "uq", "a", "keh", "v", "nq", "wja", "ul", "pfa",
             "ll", "cng", "twa", "f", "o", "v", "y", "m", "exn", "f", "mvf", "ess", "pur", "v", "e", "xrf", "jxy", "a",
             "a", "owx", "b", "whc", "o", "wxl", "n", "eg", "cp", "z", "gp", "ba", "u", "gy", "j", "d", "m", "k", "vyd",
             "ely", "uo", "upo", "dj", "l", "ad", "f", "vf", "xv", "elp", "ico", "s", "aah", "tpa", "mcf", "h", "zcq",
             "ocn", "m", "n", "uq", "ua", "c", "f", "xz", "f", "t", "lag", "kwj", "kh", "ri", "zry", "y", "lgy", "dyn",
             "mg", "o", "f", "p", "ckv", "swi", "l", "yb", "nf", "tk", "te", "jh", "ld", "lb", "b", "gka", "d", "j",
             "cj", "v", "c", "r", "d", "a", "ds", "irn", "klq", "fga", "q", "oqp", "j", "xq", "kps", "ozw", "ggi",
             "owb", "l", "h", "nvs", "ljn", "bb", "fst", "s", "s", "f", "fr", "wtq", "h", "di", "n", "chp", "bs", "uky",
             "kh", "zc", "wpk", "mt", "ied", "r", "flg", "igo", "gp", "bdo", "ge", "mz", "fpk", "mb", "scv", "eh",
             "slq", "u", "hi", "wm", "ug", "wnj", "xk", "wq", "a", "ne", "gwh", "gf", "y", "iwl", "mw", "q", "u", "b",
             "r", "deh", "tp", "fcx", "wli", "qzq", "m", "kjk", "l", "dsg", "f", "c", "tsp", "wh", "dzu", "h", "lni",
             "psw", "axq", "d", "ahl", "oxd", "uf", "vw", "eqb", "hw", "nvi", "up", "d", "hm", "zjs", "yo", "b", "lce",
             "cb", "gyo", "qo", "swx", "cp", "zz", "ojw", "v", "blb", "ndl", "pft", "bxj", "caq", "hud", "gqx", "st",
             "l", "xop", "p", "l", "z", "bnd", "t", "kn", "f", "ax", "o", "tw", "t", "l", "i", "z", "rk", "w", "w", "b",
             "ven", "is", "l", "vwv", "pwx", "kyf", "zru", "yf", "mm", "hr", "bj", "ngy", "cf", "m", "xyc", "qm", "uur",
             "d", "ju", "dg", "y", "vrk", "q", "ts", "x", "lm", "vf", "bzq", "dr", "b", "pca", "mh", "cij", "px", "qep",
             "z", "lj", "t", "c", "wv", "d", "p", "hhl", "x", "tyo", "tl", "klc", "e", "aza", "zvd", "z", "gs", "i",
             "p", "ang", "pp", "ml", "j", "mc", "pwp", "og", "se", "r", "wha", "z", "t", "lei", "uem", "a", "m", "d",
             "xg", "q", "o", "ha", "ral", "u", "pgl", "ns", "zn", "lpa", "tc", "ppo", "ufq", "bl", "w", "ebq", "h",
             "cy", "a", "kn", "k", "fen", "nco", "dnd", "abl", "kxn", "nq", "iq", "kvs", "hmf", "xz", "hkx", "fp", "qo",
             "pp", "ltj", "fb", "d", "tr", "ydg", "bmn", "d", "k", "w", "vg", "v", "hk", "mvu", "qso", "ncw", "ow",
             "ou", "wim", "wy", "ba", "grl", "geu", "rbv", "ir", "k", "v", "rb", "fog", "b", "qho", "mq", "sni", "cxa",
             "r", "ojl", "ges", "e", "fxf", "zel", "rn", "ygr", "i", "zj", "fj", "d", "p", "cz", "rzd", "r", "u", "cl",
             "aj", "wwn", "mjo", "qq", "o", "ag", "zhz", "hba", "slf", "c", "n", "xkd", "cpu", "ghy", "xem", "sf", "o",
             "xd", "w", "t", "fdz", "u", "kke", "m", "xgu", "tnl", "set", "svi", "tjp", "p", "mv", "jzy", "hqz", "wsx",
             "wza", "rn", "q", "k", "lg", "op", "y", "hx", "ioo", "mm", "nrk", "dtf", "m", "wew", "lqe", "a", "u", "fd",
             "cd", "t", "qk", "ax", "z", "t", "o", "giz", "c", "xr", "b", "cy", "yu", "r", "p", "oo", "ge", "aj", "ie",
             "qz", "nz", "u", "msq", "f", "err", "t", "m", "uzd", "n", "b", "mi", "y", "sst", "af", "hi", "u", "lwr",
             "zz", "czr", "o", "i", "w", "y", "i", "kev", "pag", "tzy", "aoy", "fpi", "yv", "x", "rbe", "l", "ac", "g",
             "fko", "ikm", "v", "ps", "ki", "o", "olr", "pc", "v", "cv", "t", "lcp", "w", "ule", "rvr", "cg", "vp",
             "bcc", "t", "dpm", "aa", "wha", "g", "aw", "hr", "lfv", "cq", "g", "dnl", "lvr", "lf", "ge", "g", "kxc",
             "l", "h", "xx", "z", "bbl", "vg", "om", "cy", "jbw", "u", "six", "z", "efd", "spn", "tdq", "x", "g", "l",
             "so", "l", "f", "jgz", "nk", "hij", "chc", "hi", "lk", "a", "i", "opy", "a", "f", "mkr", "d", "a", "e",
             "mnx", "kb", "dnc", "daz", "c", "sh", "yy", "l", "omz", "t", "uut", "esd", "qwd", "y", "ce", "kpr", "kdr",
             "m", "d", "ud", "j", "ow", "mxb", "sqk", "qxb", "k", "a", "tc", "cq", "m", "dge", "x", "m", "e", "o", "ys",
             "f", "z", "ay", "emq", "e", "api", "sru", "ipi", "nrt", "tky", "tdw", "z", "nzp", "gj", "mz", "s", "dbs",
             "f", "m", "wj", "kp", "sy", "u", "q", "rj", "qr", "ak", "yc", "vbq", "ow", "yfq", "myf", "v", "onj", "epb",
             "pws", "u", "p", "y", "cwf", "sf", "rdu", "v", "jmw", "oz", "y", "ey", "h", "oq", "ti", "li", "czc", "pq",
             "ncn", "uii", "n", "u", "ozu", "svl", "kpe", "ng", "qeg", "tw", "wjt", "a", "vx", "gq", "l", "m", "wmq",
             "vu", "bv", "q", "az", "v", "j", "s", "n", "g", "se", "tar", "at", "p", "zy", "hzo", "m", "e", "tjj", "xl",
             "ja", "m", "rrm", "ri", "m", "y", "pm", "tk", "nbs", "mzk", "qwp", "oid", "z", "vr", "wk", "n", "y", "aa",
             "eai", "kt", "nsr", "qts", "yf", "xvw", "uxc", "zbh", "qow", "r", "v", "biu", "r", "vyt", "cqa", "gnc",
             "jil", "haf", "l", "ux", "b", "y", "eq", "cvw", "mu", "weg", "l", "v", "u", "sta", "sq", "egg", "of", "w",
             "l", "p", "xg", "jm", "h", "rma", "t", "m", "q", "el", "g", "jop", "v", "mmy", "mis", "u", "zgo", "xa",
             "o", "cc", "yg", "xw", "qeo", "f", "s", "t", "ww", "pgv", "sp", "srk", "ipm", "zka", "hxe", "wo", "x",
             "jmj", "xqi", "dr", "n", "ng", "a", "l", "ygn", "s", "ffd", "xxh", "tq", "nl", "fj", "n", "fvj", "z",
             "hwj", "xu", "ao", "hco", "n", "nw", "nf", "x", "fi", "nc", "z", "f", "uu", "woo", "czg", "jeo", "d", "j",
             "wh", "wyd", "kvr", "dvj", "jon", "a", "mpd", "ejp", "x", "mqo", "mx", "cv", "f", "axg", "w", "sm", "kx",
             "ka", "v", "a", "gk", "i", "ei", "l", "u", "ct", "stx", "jx", "ec", "ktm", "fh", "w", "shv", "ffz", "qy",
             "zeh", "qea", "aau", "rod", "lw", "vmn", "wd", "j", "je", "fdd", "nks", "m", "vt", "l", "v", "ok", "pi",
             "cor", "ih", "m", "sa", "z", "rwd", "h", "an", "z", "ar", "jjf", "cih", "aub", "ayk", "paq", "ie", "mlp",
             "dch", "im", "qq", "usu", "zs", "qnn", "zf", "f", "htg", "x", "azu", "um", "bmv", "qx", "mhl", "db", "rgf",
             "fg", "sw", "n", "kta", "f", "tn", "ca", "yc", "q", "u", "ge", "fqk", "qj", "beq", "d", "xdp", "tjm",
             "apn", "tm", "e", "tgk", "oez", "s", "lat", "yg", "ix", "oj", "ev", "nhv", "gdc", "nip", "w", "x", "x",
             "xg", "qij", "q", "fmr", "w", "y", "ny", "ekw", "bq", "j", "bil", "h", "isz", "d", "q", "zhd", "tb", "uy",
             "r"]
    word1 = "swi"
    word2 = "qq"
    sol = Solution()
    print(sol.findClosest(words, word1, word2))
