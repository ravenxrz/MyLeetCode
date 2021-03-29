from typing import List


class Solution:
    class UFS:
        def __init__(self, elements: List[str]):
            self.ufs = {}
            for elem in elements:
                self.ufs[elem] = elem

        def findFather(self, elem: str) -> str:
            ret = self.ufs.get(elem)
            if ret is None:
                raise Exception("elem is not in this set")
            while ret != self.ufs.get(ret):
                ret = self.ufs.get(ret)

            root = ret
            ret = elem
            # path compaction
            while ret != root:
                ret = self.ufs.get(ret)
                self.ufs[ret] = root
            return root

        def isSameSet(self, elem1: str, elem2: str) -> bool:
            return self.findFather(elem1) == self.findFather(elem2)

        def checkInAndSet(self, elem: str):
            """
            检查elem是否在并查集中，如果不在就将其加入，独自一组
            :param elem:
            :return:
            """
            if self.ufs.get(elem) is None:
                self.ufs[elem] = elem

        def merge(self, elem1: str, elem2: str):
            x = self.findFather(elem1)
            y = self.findFather(elem2)
            if x == y:
                return
            # do merge
            if x <= y:
                self.ufs[y] = x
            else:
                self.ufs[x] = y

        def doCompaction(self):
            for key in self.ufs.keys():
                father = self.findFather(key)
                self.ufs[key] = father

    def trulyMostPopular(self, names: List[str], synonyms: List[str]) -> List[str]:
        # parse names
        name_num_dict = {}
        for name in names:
            name, num = self.parse_names(name)
            name_num_dict[name] = num

        # create origin ufs
        ufs = Solution.UFS(list(name_num_dict.keys()))

        # merge same set by synonyms
        for syn in synonyms:
            name1, name2 = self.parse_relation(syn)
            ufs.checkInAndSet(name1)
            ufs.checkInAndSet(name2)
            # both name1 and name2 are in ufs
            if ufs.isSameSet(name1, name2):
                continue
            # ok, now we can merge
            ufs.merge(name1, name2)

        # do a compaction, this is necessary
        ufs.doCompaction()

        # add children's num to the "father" node
        father_set = set()
        for name in ufs.ufs:
            father = ufs.findFather(name)
            # exclude elements that is not in the name_num_dict
            if name_num_dict.get(name) is None:
                continue
            # record father elements which we will return back to user
            father_set.add(father)
            if father == name:
                continue
            name_num_dict[father] += name_num_dict[name]

        # get answer through father_set
        ans = []
        for name in father_set:
            ans.append(name + "(" + str(name_num_dict[name]) + ")")
        return ans

    def parse_names(self, name: str) -> (str, int):
        idx1 = name.find('(')
        idx2 = name.find(')')
        assert idx1 != -1 and idx2 != -1, "name is not in a correct format"
        return name[:idx1], int(name[idx1 + 1:idx2])

    def parse_relation(self, pair: str) -> (str, str):
        idx = pair.find(',')
        assert idx != -1
        return pair[1:idx], pair[idx + 1:-1]


if __name__ == '__main__':
    names = ["Fcclu(70)", "Ommjh(63)", "Dnsay(60)", "Qbmk(45)", "Unsb(26)", "Gauuk(75)", "Wzyyim(34)", "Bnea(55)",
             "Kri(71)", "Qnaakk(76)", "Gnplfi(68)", "Hfp(97)", "Qoi(70)", "Ijveol(46)", "Iidh(64)", "Qiy(26)",
             "Mcnef(59)", "Hvueqc(91)", "Obcbxb(54)", "Dhe(79)", "Jfq(26)", "Uwjsu(41)", "Wfmspz(39)", "Ebov(96)",
             "Ofl(72)", "Uvkdpn(71)", "Avcp(41)", "Msyr(9)", "Pgfpma(95)", "Vbp(89)", "Koaak(53)", "Qyqifg(85)",
             "Dwayf(97)", "Oltadg(95)", "Mwwvj(70)", "Uxf(74)", "Qvjp(6)", "Grqrg(81)", "Naf(3)", "Xjjol(62)",
             "Ibink(32)", "Qxabri(41)", "Ucqh(51)", "Mtz(72)", "Aeax(82)", "Kxutz(5)", "Qweye(15)", "Ard(82)",
             "Chycnm(4)", "Hcvcgc(97)", "Knpuq(61)", "Yeekgc(11)", "Ntfr(70)", "Lucf(62)", "Uhsg(23)", "Csh(39)",
             "Txixz(87)", "Kgabb(80)", "Weusps(79)", "Nuq(61)", "Drzsnw(87)", "Xxmsn(98)", "Onnev(77)", "Owh(64)",
             "Fpaf(46)", "Hvia(6)", "Kufa(95)", "Chhmx(66)", "Avmzs(39)", "Okwuq(96)", "Hrschk(30)", "Ffwni(67)",
             "Wpagta(25)", "Npilye(14)", "Axwtno(57)", "Qxkjt(31)", "Dwifi(51)", "Kasgmw(95)", "Vgxj(11)",
             "Nsgbth(26)",
             "Nzaz(51)", "Owk(87)", "Yjc(94)", "Hljt(21)", "Jvqg(47)", "Alrksy(69)", "Tlv(95)", "Acohsf(86)",
             "Qejo(60)", "Gbclj(20)", "Nekuam(17)", "Meutux(64)", "Tuvzkd(85)", "Fvkhz(98)", "Rngl(12)", "Gbkq(77)",
             "Uzgx(65)", "Ghc(15)", "Qsc(48)", "Siv(47)"]
    synonyms = ["(Gnplfi,Qxabri)", "(Uzgx,Siv)", "(Bnea,Lucf)", "(Qnaakk,Msyr)", "(Grqrg,Gbclj)", "(Uhsg,Qejo)",
                "(Csh,Wpagta)", "(Xjjol,Lucf)", "(Qoi,Obcbxb)", "(Npilye,Vgxj)", "(Aeax,Ghc)", "(Txixz,Ffwni)",
                "(Qweye,Qsc)", "(Kri,Tuvzkd)", "(Ommjh,Vbp)", "(Pgfpma,Xxmsn)", "(Uhsg,Csh)", "(Qvjp,Kxutz)",
                "(Qxkjt,Tlv)", "(Wfmspz,Owk)", "(Dwayf,Chycnm)", "(Iidh,Qvjp)", "(Dnsay,Rngl)", "(Qweye,Tlv)",
                "(Wzyyim,Kxutz)", "(Hvueqc,Qejo)", "(Tlv,Ghc)", "(Hvia,Fvkhz)", "(Msyr,Owk)", "(Hrschk,Hljt)",
                "(Owh,Gbclj)", "(Dwifi,Uzgx)", "(Iidh,Fpaf)", "(Iidh,Meutux)", "(Txixz,Ghc)", "(Gbclj,Qsc)",
                "(Kgabb,Tuvzkd)", "(Uwjsu,Grqrg)", "(Vbp,Dwayf)", "(Xxmsn,Chhmx)", "(Uxf,Uzgx)"]
    # names = ["a(10)", "c(13)"]
    # synonyms = ["(a,b)", "(c,d)", "(b,c)"]
    sol = Solution()
    print(sol.trulyMostPopular(names, synonyms))
