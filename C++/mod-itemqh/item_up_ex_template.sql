/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50528
Source Host           : localhost:3306
Source Database       : world

Target Server Type    : MYSQL
Target Server Version : 50528
File Encoding         : 65001

Date: 2018-05-22 17:48:39
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for item_up_ex_template
-- ----------------------------
DROP TABLE IF EXISTS `item_up_ex_template`;
CREATE TABLE `item_up_ex_template` (
  `entry` mediumint(8) NOT NULL,
  `exitem_1` mediumint(8) NOT NULL,
  `excount_1` mediumint(8) NOT NULL,
  `exitem_2` mediumint(8) NOT NULL,
  `excount_2` mediumint(8) NOT NULL,
  `exitem_3` mediumint(8) NOT NULL,
  `excount_3` mediumint(8) NOT NULL,
  `exitem_4` mediumint(8) NOT NULL,
  `excount_4` mediumint(8) NOT NULL,
  `exitem_5` mediumint(8) NOT NULL,
  `excount_5` mediumint(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of item_up_ex_template
-- ----------------------------
INSERT INTO `item_up_ex_template` VALUES ('710000', '54586', '1', '54581', '1', '0', '0', '0', '0', '0', '0');
