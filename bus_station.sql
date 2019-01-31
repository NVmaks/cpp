-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Хост: localhost
-- Время создания: Янв 23 2019 г., 16:04
-- Версия сервера: 8.0.13
-- Версия PHP: 7.2.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `bus_station`
--

-- --------------------------------------------------------

--
-- Структура таблицы `bus`
--

CREATE TABLE `bus` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `model` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `number` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `places` int(11) NOT NULL,
  `status` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `bus`
--

INSERT INTO `bus` (`id`, `model`, `number`, `places`, `status`) VALUES
(1, 'Citroen', 'К065ТА12', 18, NULL),
(2, 'Citroen', 'В245ДЛ55', 18, NULL),
(3, 'Citroen', 'Р589МН45', 18, NULL),
(4, 'Citroen', 'З735ТТ43', 18, NULL),
(5, 'Citroen', 'Ж103КШ12', 18, NULL),
(6, 'Citroen', 'Е034КЛ12', 18, NULL),
(7, 'Citroen', 'З712УМ12', 18, NULL),
(8, 'Mercedes-Benz', 'Б521ВК12', 19, NULL),
(9, 'Mercedes-Benz', 'К100ЧГ12', 19, NULL),
(10, 'Peugeot', 'У321КК21', 17, NULL),
(11, 'Peugeot', 'Н777ЛО21', 17, NULL),
(12, 'Peugeot', 'У783ЗО23', 17, NULL);

-- --------------------------------------------------------

--
-- Структура таблицы `dispatchers`
--

CREATE TABLE `dispatchers` (
  `login` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `dispatchers`
--

INSERT INTO `dispatchers` (`login`, `password`) VALUES
('admin', 'admin');

-- --------------------------------------------------------

--
-- Структура таблицы `routes`
--

CREATE TABLE `routes` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `point_a` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `point_b` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `time` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `routes`
--

INSERT INTO `routes` (`id`, `point_a`, `point_b`, `time`) VALUES
(1, 'Йошкар-Ола', 'Волжск', '2:00'),
(2, 'Волжск', 'Йошкар-Ола', '2:00'),
(3, 'Козьмодемьянск', 'Йошкар-Ола', '3:00'),
(4, 'Йошкар-Ола', 'Козьмодемьянск', '3:00'),
(5, 'Звенигово', 'Йошкар-Ола', '1:30'),
(6, 'Йошкар-Ола', 'Звенигово', '1:30');

-- --------------------------------------------------------

--
-- Структура таблицы `trips`
--

CREATE TABLE `trips` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `id_routes` int(11) NOT NULL,
  `id_bus` int(11) DEFAULT NULL,
  `time_a` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `time_b` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `places` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Дамп данных таблицы `trips`
--

INSERT INTO `trips` (`id`, `id_routes`, `id_bus`, `time_a`, `time_b`, `places`) VALUES
(1, 1, NULL, '7:00', '9:00', NULL),
(2, 1, NULL, '9:00', '11:00', NULL),
(3, 1, NULL, '11:00', '13:00', NULL),
(4, 1, NULL, '13:00', '15:00', NULL),
(5, 1, NULL, '15:00', '17:00', NULL),
(6, 2, NULL, '6:30', '8:30', NULL),
(7, 2, NULL, '8:30', '10:30', NULL),
(8, 2, NULL, '10:30', '12:30', NULL),
(9, 2, NULL, '12:30', '14:30', NULL),
(10, 2, NULL, '14:30', '16:30', NULL),
(11, 2, NULL, '16:30', '18:30', NULL),
(12, 3, NULL, '5:00', '8:00', NULL),
(13, 3, NULL, '8:00', '11:00', NULL),
(14, 3, NULL, '11:00', '14:00', NULL),
(15, 3, NULL, '14:00', '17:00', NULL),
(16, 3, NULL, '17:00', '20:00', NULL),
(17, 4, NULL, '7:00', '10:00', NULL),
(18, 4, NULL, '10:00', '13:00', NULL),
(19, 4, NULL, '13:00', '16:00', NULL),
(20, 4, NULL, '16:00', '19:00', NULL),
(21, 5, NULL, '6:00', '7:30', NULL),
(22, 5, NULL, '8:00', '9:30', NULL),
(23, 5, NULL, '10:00', '11:30', NULL),
(24, 5, NULL, '12:00', '13:30', NULL),
(25, 5, NULL, '14:00', '15:30', NULL),
(26, 5, NULL, '16:00', '17:30', NULL),
(27, 5, NULL, '18:00', '19:30', NULL),
(28, 6, NULL, '6:00', '7:30', NULL),
(29, 6, NULL, '8:00', '9:30', NULL),
(30, 6, NULL, '10:00', '11:30', NULL),
(31, 6, NULL, '12:00', '13:30', NULL),
(32, 6, NULL, '14:00', '15:30', NULL),
(33, 6, NULL, '16:00', '17:30', NULL);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `bus`
--
ALTER TABLE `bus`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `number` (`number`);

--
-- Индексы таблицы `routes`
--
ALTER TABLE `routes`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `trips`
--
ALTER TABLE `trips`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `bus`
--
ALTER TABLE `bus`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT для таблицы `routes`
--
ALTER TABLE `routes`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT для таблицы `trips`
--
ALTER TABLE `trips`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=34;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
