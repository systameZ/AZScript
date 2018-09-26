/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50528
Source Host           : localhost:3306
Source Database       : auth

Target Server Type    : MYSQL
Target Server Version : 50528
File Encoding         : 65001

Date: 2018-05-22 17:48:52
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for vip_up_info
-- ----------------------------
DROP TABLE IF EXISTS `vip_up_info`;
CREATE TABLE `vip_up_info` (
  `level` mediumint(8) NOT NULL,
  `needjf` mediumint(8) NOT NULL,
  `give_1` mediumint(8) NOT NULL,
  `give_1_type` mediumint(8) NOT NULL,
  `give_2` mediumint(8) NOT NULL,
  `give_2_type` mediumint(8) NOT NULL,
  `give_3` mediumint(8) NOT NULL,
  `give_3_type` mediumint(8) NOT NULL,
  `give_4` mediumint(8) NOT NULL,
  `give_4_type` mediumint(8) NOT NULL,
  `give_5` mediumint(8) NOT NULL,
  `give_5_type` mediumint(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of vip_up_info
-- ----------------------------
INSERT INTO `vip_up_info` VALUES ('1', '1000', '54586', '1', '0', '0', '0', '0', '0', '0', '0', '0');
INSERT INTO `vip_up_info` VALUES ('2', '3000', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');
