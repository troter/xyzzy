## �T�v ##

multiframe�ł̑S������p�b�P�[�W�ł��B
C-x 5 2
�ŐV�����t���[�����J���܂��B


## �z�z�ꏊ ##

�ŐV�ł͈ȉ�����_�E�����[�h�o���܂��B
https://bitbucket.org/mumurik/xyzzy/downloads

github�ւ̏�芷���]�����B
https://github.com/mumurik/xyzzy


## �Z�b�g�A�b�v ##

�z�z��zip��W�J����xyzzy.exe�����s���邾���ł��B 
�����̊��ɏ㏑������ꍇ��xyzzy.wxp���폜���Ă��������B

�܂��A�����lisp�p�b�P�[�W�͂��̂܂܂ł͓����Ȃ������������Ă��܂��B
�ȉ����Q�Ƃ��Ă��������B
https://bitbucket.org/mumurik/xyzzy/wiki/%E5%8B%95%E3%81%8B%E3%81%AA%E3%81%84lisp%E3%83%91%E3%83%83%E3%82%B1%E3%83%BC%E3%82%B8%E4%B8%80%E8%A6%A7


## �X�V���� ##

== 0.2.3.3����0.2.3.4�ւ̏C���_ ==

����͎��fix���ł������A���\�ύX����Ă܂��B

* WoW64����system32�ȉ��̃t�@�C����������悤��(Thanks to Part17 638��)
* frame-hook�n��emacs�Ƃ��݊���
** *before-make-frame-hook*��frame�������O��
** *after-make-frame-hook*��*after-make-frame-functions*�Ƀ��l�[��
** *delete-frame-functions*��ǉ�
** C-x 5 o other-frames�̎���
* UnitTest������ (Thanks to bowbow99��, southly���j
* *scratch*<2>�Ƃ������������̂��o���Ă��̂����� (Thanks to tn���j
* previous-pseudo-frame�����Ă��̂�fix (Thanks to youz���j

���̂ق��o�Ofix������B

== 0.2.3.2����0.2.3.3�ւ̏C���_ ==

���southly����github�ɂ�������p�b�`�̎�荞�݂ƁA2310����USB�N���p�b�`���i�ύX������Łj��荞�݂܂����B
southly���A2310���AMIYAMUKO���A�y�уX����Wiki�Ƀp�b�`�����J���Ă��ꂽ�F�l�Ɋ��ӁB

** southly����github����̎�荞�� **

�ȉ��Ɏ�ȕ��������Ă����܂��B

* IME�̑O��t�B�[�h�o�b�N�̃T�|�[�g(http://fixdap.com/p/xyzzy/7376/)
* lisp��format�֐��̋����̗ǂ�������Ȃ��������C��
* si:putenv�̒ǉ�(http://d.hatena.ne.jp/miyamuko/20100910/xyzzy_putenv)
* hashtable��rehash���ɃN���A�����G���g�����Ԉ���ă}�[�N���悤�Ƃ��ė�������̏C��(https://github.com/southly/xyzzy.src/commit/88c011a05c0fb88864c1477f3b3d88da60cad9f3)
* tar32.dll��Ver. 2.35�ȍ~���痘�p�o����lzma�y��xz�̈��k�W�J�ɑΉ�
* DLL�v�����[�h�U���ɑ΂���Ή��B���݂̃��[�L���O�f�B���N�g����dll���[�h�̌����Ώۂ���O��(https://github.com/southly/xyzzy.src/commit/1fa86d358323dd4c17abda724f675b8b686beea9, https://github.com/southly/xyzzy.src/commit/a5ac9b45d187724251c9963e71862ee447475889)

���m�ȃ��X�g��github�̗������Q�Ƃ��������Bhttps://github.com/mumurik/xyzzy/commits/master

** USB�N�� **

* xyzzy.exe�Ɠ����p�X��xyzzy.ini������ꍇ�A����ini�t�@�C�����g����悤�ɏC��
* ini�t�@�C������usbHomeDir��usbConfigDir��ǉ��B���̒l��xyzzy.exe����̑��΃p�X�Ƃ��ĉ��߂���Ahome��config��dir�Ƃ��Ďg����
* archiver��dll�̃��[�h��Ƃ���xyzzy.exe�Ɠ����t�H���_��lib/��ǉ�

�ڍׂ͈ȉ���url�ŁBhttps://bitbucket.org/mumurik/xyzzy/wiki/USB%E8%B5%B7%E5%8B%95


** southly����github **

https://github.com/southly/xyzzy.src
master��nanri-master����Ƀ}�[�W�B

** 2310����patch **

http://blog.2310.net/archives/618
�ixyzzy-0.2.235-2009092301.patch�̓��A�֘A������K�p�j


== 0.2.3.1����0.2.3.2�ւ̏C���_ ==

* �u�w�蕝�Ő܂�Ԃ��v���u���ʐݒ��ۑ��v�ŕۑ����Ă��ۑ�����Ȃ��i�悤�Ɍ�����j�o�O���C��
* �����t���[���������Ԃŕ��G�Ȑ؂���A�\��t�����J��Ԃ��Əꍇ�ɂ���Ă͗����鎖������̂��C��
* ���ݑI�𒆂Ŗ����o�b�t�@�o�[���X�V�����悤�ɏC��

== 0.2.2.235����0.2.3.1�ւ̏C���_ ==

* �����t���[���Ή� (C-x 5 2, �܂��֘A��C-x 5 1, C-x 5 0�������Ă���)
* *features*��:multiple-frames������
* split-window-vertically��C-5����C-3��
* ��ʒ[�̐܂�Ԃ����E�B���h�E�P�ʂł����Ɠ����悤��
* ghost��������(����������܂���A���ĂȂ�����)�ɂ�C-g�������ƌ����悤��
* mode-line-format��%/��ǉ� (�o�b�t�@�̒��Ō��݂̃L�����b�g����%�̈ʒu�ɂ��邩�A��\���j



## �ύX���̃o�[�W���� ##
�x�[�X�͈ȉ���URL��xyzzy-0.2.2.235.zip�����ɂ��Ă���܂��B
http://www.jsdlab.co.jp/~kamei/




